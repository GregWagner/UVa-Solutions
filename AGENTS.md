# AGENTS.md

Personal competitive-programming solutions repo (UVa Online Judge, Kattis, CSES, Codeforces, NeetCode).
No build system, no tests, no CI: each solution is a self-contained program compiled directly with g++.

## Solve/workflow rules (user preferences)

- C++17 only; one self-contained source file per problem. No C++20+ unless explicitly requested.
- Read only stdin, write only stdout. Never print prompts, debug text, or extra labels. Match the expected
  output exactly — UVa/Judges penalize stray whitespace (PE) and trailing junk.
- Standard fast-I/O preamble: `std::ios::sync_with_stdio(false); std::cin.tie(nullptr);`
- Handle both loop-until-EOF (`while (std::cin >> x)`) and explicit test-count inputs; watch for blank lines.
- Check integer ranges before choosing types (32-bit vs 64-bit).
- Prefer simple, reliable algorithms over clever/unnecessary abstractions; avoid dynamic allocation in hot paths.
- This is a learning repo: when asked for help, guide with questions and hints first; write a full solution only
  when explicitly requested. Review before rewriting; propose minimal patches and explain each change.
- "Done" requires: (1) algorithm and complexity explained, (2) compiles clean with warnings enabled,
  (3) sample passes, (4) edge cases pass, (5) final diff inspected.

## Build & run (no Makefile/CMake)

Compile a single file directly, then run it with the problem's sample input:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp -o main
./main < input          # then compare against the paired output / expected file
```

Debug builds: add `-g -fsanitize=address,undefined`.

## Layout

- `Competitive_Programming_4/` — active work, organized by CP4 book chapter:
  - `Chapter_XX_*/<section>/<PROBLEMID>_<Name>/main.cpp` with sample `input` (sometimes `in`) and expected
    `output` beside it. Some problems also have `Main.java` (UVa Java requires public `class Main`, no package).
  - `Kattis/` subdirs inside chapters hold flat, one-file solutions with no input files.
  - `cpbook-code/` — official CP4 reference code (the book's algorithm library; free to copy/adapt).
    Its chapter dirs are named differently from the active ones (`Chapter_04_Graphs` vs `Chapter_04_Graph`).
- Root: historical problem folders (`Codeforces/`, `CSES/`, `NeetCode/`, `Anagram/`, `Palindrome/`, number-prefixed
  dirs like `10391_Compound_Words/`) use mixed layouts — per-problem dirs or flat `.cpp` files. `README.txt` is a
  personal progress log, not documentation.
- Scratch (safe to ignore/clean): `Competitive_Programming_4/temp/`, `test.cpp`, `a.out`.

## Gotchas

- `.vscode/` configs are stale, gitignored Windows paths (MinGW, `c:/Projects/UVa-Solutions`) — do not mirror them;
  this machine is Linux with g++ (GCC 16).
- `opencode.json` (repo root): shell commands require permission; `git push` is always denied.
- `open_code_steps.md`, `open_code_gemini.md`, and `step_0*.txt` (root) are earlier workflow drafts; their accepted
  rules are consolidated here — don't treat them as additional instruction sources.