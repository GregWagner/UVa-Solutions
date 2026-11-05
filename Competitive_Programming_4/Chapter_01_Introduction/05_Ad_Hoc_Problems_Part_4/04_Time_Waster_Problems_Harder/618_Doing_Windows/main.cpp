#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <utility>

/**
 * UVA 618 - Doing Windows
 *
 * A screen (Ws x Hs pixels) has to be covered exactly, without overlap, by four
 * windows.  A window may be resized and moved, but nothing else: the statement
 * keeps the aspect ratio width/height unchanged, so a window is never rotated.
 *
 * Resizing keeps the aspect ratio, so window i can only have sizes
 * (k * wi, k * hi) with k a positive integer, where (wi, hi) is the reduced
 * (coprime) form of its initial size.  The screen therefore has to be tiled by
 * four axis-aligned rectangles with those fixed proportions.
 *
 * Key facts used here:
 *
 *  1) Every tiling of a rectangle by at most four rectangles is "guillotine":
 *     some straight cut across the whole region splits it into two parts, each
 *     tiled by fewer windows (the smallest non-slicing tiling needs 5 pieces).
 *     So the search only has to consider vertical and horizontal cuts.
 *
 *  2) For a region tiled by a set S of windows, only its aspect ratio
 *     width/height matters when it is glued to another region.  The set of
 *     aspect ratios a set of windows can produce is computed by a small DP:
 *
 *        side by side  (vertical cut):  a = a1 + a2
 *        stacked      (horizontal cut):  a = 1 / (1/a1 + 1/a2)
 *
 *     Only sets of at most three windows need aspect ratios (the top level cut
 *     splits the four windows into 1+3 or 2+2), which keeps the numbers small.
 *
 *  3) Given the aspect ratio num/den (reduced) of a sub-region, the size of
 *     that sub-region is forced by the cut: for a vertical cut at width x the
 *     left part has aspect x/h = num/den, hence den | h and x = num * (h/den);
 *     for a horizontal cut at height y the top part has aspect w/y = num/den,
 *     hence num | w and y = den * (w/num).
 *
 * All arithmetic is done with exact integers (no floating point epsilon), so
 * "almost equal" aspect ratios are never mistaken for equal ones.  The aspect
 * ratios of three windows are products of at most three window dimensions, so
 * 64 bit integers cover window sizes up to roughly 10^6 pixels.
 */

typedef long long int64;

namespace {

int64 gcd64(int64 a, int64 b) {
    while (b != 0) {
        int64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Reduced fraction num/den with num, den > 0.
struct Fraction {
    int64 num, den;

    Fraction() : num(0), den(1) {}
    Fraction(int64 n, int64 d) : num(n), den(d) {}

    void reduce() {
        int64 g = gcd64(num, den);
        num /= g;
        den /= g;
    }

    bool operator<(const Fraction& other) const {
        if (num != other.num) return num < other.num;
        return den < other.den;
    }
};

int popcount(int mask) {
    int c = 0;
    while (mask != 0) {
        c += mask & 1;
        mask >>= 1;
    }
    return c;
}

int lowestBitIndex(int mask) {
    int i = 0;
    while ((mask & 1) == 0) {
        mask >>= 1;
        ++i;
    }
    return i;
}

class DoingWindows {
public:
    DoingWindows(int64 screenW, int64 screenH, const int64 windowW[4],
                 const int64 windowH[4])
        : screenW_(screenW), screenH_(screenH) {
        for (int i = 0; i < 4; ++i) {
            int64 g = gcd64(windowW[i], windowH[i]);
            windowW_[i] = windowW[i] / g;   // reduced size of window i
            windowH_[i] = windowH[i] / g;
        }
    }

    bool canCover() {
        buildAspects();
        return canTile(15, screenW_, screenH_);
    }

private:
    static const int MASK_COUNT = 16;

    int64 screenW_, screenH_;
    int64 windowW_[4], windowH_[4];

    // aspects[mask] = aspect ratios (width/height) that the windows of mask
    // can produce.  Only masks with at most three windows are needed.
    std::set<Fraction> aspects[MASK_COUNT];

    std::map<std::tuple<int, int64, int64>, bool> memo_;

    void addAspect(int mask, int64 num, int64 den) {
        Fraction f(num, den);
        f.reduce();
        aspects[mask].insert(f);
    }

    void buildAspects() {
        for (int mask = 1; mask < MASK_COUNT; ++mask) {
            if (popcount(mask) > 3) continue;

            if ((mask & (mask - 1)) == 0) {   // single window
                int i = lowestBitIndex(mask);
                aspects[mask].insert(Fraction(windowW_[i], windowH_[i]));
                continue;
            }

            for (int left = (mask - 1) & mask; left != 0; left = (left - 1) & mask) {
                int right = mask ^ left;
                for (std::set<Fraction>::const_iterator it1 = aspects[left].begin();
                     it1 != aspects[left].end(); ++it1) {
                    for (std::set<Fraction>::const_iterator it2 = aspects[right].begin();
                         it2 != aspects[right].end(); ++it2) {
                        // side by side: a = a1 + a2
                        addAspect(mask,
                                  it1->num * it2->den + it2->num * it1->den,
                                  it1->den * it2->den);
                        // stacked: a = 1 / (1/a1 + 1/a2)
                        addAspect(mask,
                                  it1->num * it2->num,
                                  it1->den * it2->num + it2->den * it1->num);
                    }
                }
            }
        }
    }

    // Can the windows of 'mask' tile a region of aspect width/height?
    bool aspectPossible(int mask, int64 w, int64 h) const {
        int64 g = gcd64(w, h);          // both the region and the stored
        int64 rw = w / g, rh = h / g;    // ratios are in lowest terms
        for (std::set<Fraction>::const_iterator it = aspects[mask].begin();
             it != aspects[mask].end(); ++it) {
            if (rw == it->num && rh == it->den) return true;
        }
        return false;
    }

    bool canTile(int mask, int64 w, int64 h) {
        if (w <= 0 || h <= 0) return false;

        std::tuple<int, int64, int64> key(mask, w, h);
        std::map<std::tuple<int, int64, int64>, bool>::const_iterator it =
            memo_.find(key);
        if (it != memo_.end()) return it->second;

        bool result = compute(mask, w, h);
        memo_[key] = result;
        return result;
    }

    bool compute(int mask, int64 w, int64 h) {
        if ((mask & (mask - 1)) == 0) {   // a single window fills the region
            int i = lowestBitIndex(mask);
            if (w % windowW_[i] != 0) return false;
            int64 k = w / windowW_[i];
            if (k < 1) return false;
            return h % windowH_[i] == 0 && h / windowH_[i] == k;
        }

        // The region must have an aspect ratio the windows can produce.
        if (!aspects[mask].empty() && !aspectPossible(mask, w, h)) return false;

        for (int part = (mask - 1) & mask; part != 0; part = (part - 1) & mask) {
            int rest = mask ^ part;

            // Vertical cut: 'part' covers the left part (x, h), 'rest' the right
            // part (w - x, h).  x/h = num/den, so den | h and x = num * (h/den).
            for (std::set<Fraction>::const_iterator f = aspects[part].begin();
                 f != aspects[part].end(); ++f) {
                if (h % f->den != 0) continue;
                int64 k = h / f->den;
                if (f->num > (w - 1) / k) continue;   // x would not fit
                int64 x = f->num * k;
                if (x < 1) continue;
                if (canTile(part, x, h) && canTile(rest, w - x, h)) return true;
            }

            // Horizontal cut: 'part' covers the upper part (w, y), 'rest' the
            // lower part (w, h - y).  w/y = num/den, so num | w and
            // y = den * (w/num).
            for (std::set<Fraction>::const_iterator f = aspects[part].begin();
                 f != aspects[part].end(); ++f) {
                if (w % f->num != 0) continue;
                int64 k = w / f->num;
                if (f->den > (h - 1) / k) continue;   // y would not fit
                int64 y = f->den * k;
                if (y < 1) continue;
                if (canTile(part, w, y) && canTile(rest, w, h - y)) return true;
            }
        }
        return false;
    }
};

}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64 screenW, screenH;
    int caseNumber = 0;

    while (std::cin >> screenW >> screenH) {
        if (screenW == 0 && screenH == 0) break;

        int64 windowW[4], windowH[4];
        for (int i = 0; i < 4; ++i) {
            std::cin >> windowW[i] >> windowH[i];
        }

        DoingWindows solver(screenW, screenH, windowW, windowH);
        ++caseNumber;
        std::cout << "Set " << caseNumber << ": "
                  << (solver.canCover() ? "Yes" : "No") << '\n';
    }

    return 0;
}
