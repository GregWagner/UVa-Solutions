# AGENTS.md — Competitive_Programming_4

This is a subdirectory of the UVa solutions repo. The canonical instruction file lives one level up at
`/mnt/games/uva/AGENTS.md` (OpenCode loads it automatically) — read that first.

Only facts specific to this directory:

- Per-problem dirs: `Chapter_XX_*/<section>/<PROBLEMID>_<Name>/main.cpp` with sample `input` (or `in`) and
  expected `output` beside it; some problems add `Main.java` (UVa Java: public `class Main`, no package).
- `Kattis/` subdirs contain flat one-file solutions with no input files.
- `cpbook-code/` is upstream CP4 book reference code (free to adapt); its chapter names differ from the active ones
  (`Chapter_04_Graphs` here vs `Chapter_04_Graph` above).
- No build system: compile each file directly, e.g. `g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp -o main`,
  then `./main < input`. `temp/`, `test.cpp`, `a.out` are scratch.