Explanation — UVa 11614 Etruscan Warriors Never Play Chess

1. The problem

Warriors stand in rows: row 1 has 1 warrior, row 2 has 2, row 3 has 3, … Given s warriors total, find how many complete rows you can form (leftovers that don't fill the next row are discarded). Examples from the statement: s = 7 → 3 rows (1+2+3 = 6 used, 1 left over).

So you need the largest n such that:

1 + 2 + … + n = n(n+1)/2  ≤  s

n(n+1)/2 is the n-th triangular number T(n) — the fact you added to the header comment.

2. Getting a closed-form estimate (the comment block)

You can't iterate up to n (s is up to 10¹⁸ → n up to ~1.4 billion), so solve for n algebraically:

n(n+1)/2 = s
n² + n − 2s = 0          ← quadratic in n, with a=1, b=1, c=−2s

Quadratic formula, keeping only the + root (rows can't be negative):

n = (−1 + √(1 + 8s)) / 2

Check with s = 10: √(1+80) = 9, (−1+9)/2 = 4 ✓ (T(4) = 10 exactly).

When s is not triangular (e.g. s = 7): the true value is ≈ 3.55, and taking the floor gives 3 ✓. That's why the code truncates the double with a cast — truncation toward zero equals floor here, since the result is always ≥ 0.

3. Why the two while loops exist (the bug we just fixed)

std::sqrt works in double, which stores only ~15–16 significant digits. For huge s the computed value can land just across an integer boundary — e.g. for s = 28580021150045279 the exact answer is 239081663, but the floating-point result truncated to 239081664. Off by one!

The fix: treat double only as an estimate, then snap to the truth with exact integer arithmetic:

while (n * (n + 1) / 2 > number_of_warriors) { --n; }   // estimate too high → step down

while ((n + 1) * (n + 2) / 2 <= number_of_warriors) { ++n; }  // too low → step up

Each loop asks the defining question directly — "does n rows fit in s warriors?" — using integer math that is exact (max n ≈ 1.4×10⁹ → product ≈ 10¹⁸, well inside uint64_t). The estimate's error is far less than 1, so each loop runs at most one iteration in practice; they're a safety net, not a search.

This is the standard pattern: fast approximate answer → cheap exact correction.

Two small details in that line:

- static_cast<double>(number_of_warriors) first, so 8 * warriors is
  a floating-point multiply — this also sidesteps the integer
  overflow that 8 * s would hit above 2⁶¹.
- The result goes into a uint64_t because n can reach
  ~1.4×10⁹ — larger than 32-bit could hold if bounds were looser,
  and it makes the correction-loop arithmetic uint64_t throughout.

4. I/O structure

std::ios::sync_with_stdio(false);      // untie C streams → faster cin/cout
std::ostringstream output;             // buffer all answers...
std::cout << output.str();             // ...write once at the end

- First line = test count → while (test_cases--) runs exactly that
  many times (this problem does give a count, unlike EOF-style
  problems such as 10071).
- Everything else is the standard house pattern: no prompts, one
  value per line, newline after each — byte-exact output.

5. Complexity
- Time: O(1) per test case (one sqrt + ≤2 correction steps) →
  O(T) overall.
- Memory: O(T) for the output buffer, O(1) otherwise.

Quick self-check questions

1. Why does static_cast truncation correctly implement floor here
   (when could truncation and floor disagree)?

2. For which s does the first correction loop actually fire — and
   why is it guaranteed to terminate?

3. If the problem allowed s ≤ 2⁶⁴, which line would break first:
   the estimate or the correction loops?
