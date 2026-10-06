Use OpenCode as a pair programmer and debugger, not as a one-click solution
generator. For UVA problems, the most effective workflow is:

1) understand the algorithm yourself,
2) ask OpenCode to critique or improve your reasoning,
3) implement locally,
4) test against samples and generated edge cases,
5) submit only after checking UVA’s strict I/O requirements.

OpenCode can run in a terminal, desktop app, or IDE extension. The official
setup uses opencode, and /init creates an AGENTS.md file containing
project-specific context. Its Plan mode can propose changes without editing
files, while /undo and /redo can revert or restore changes.

### Put your rules in AGENTS.md
Give OpenCode instructions that match UVA:

# UVA Competitive Programming Rules

- Use C++17 unless I explicitly request another language.
- Produce one self-contained source file.
- Read only from stdin and write only to stdout.
- Never print prompts, explanations, debugging text, or extra labels.
- Match the required output formatting exactly.
- Carefully handle multiple test cases and blank lines.
- Check integer ranges before choosing types.
- Prefer simple, reliable algorithms over unnecessary abstractions.
- Before declaring the solution finished:
  1. explain the algorithm and complexity,
  2. compile with warnings,
  3. test the sample,
  4. test edge cases,
  5. inspect the final diff.

UVA programs use standard input and standard output. Its submission
specification also requires a main entry point and warns against opening
files or using extra output. Java submissions have additional restrictions,
including a Main class and no package declaration.

### Start every problem with analysis, not code
Create a problem directory:

mkdir 100
cd 100
touch main.cpp sample.in notes.md
opencode
Paste the complete problem statement and use a prompt like:
-------------------------------------------------------------------------------
I am solving UVA problem xxx.

Here is the complete statement:
[paste statement]

Do not write code yet.

First provide:

1. A precise restatement of the input and output.
2. The important constraints and integer bounds.
3. The algorithmic observation.
4. A proof or justification of correctness.
5. Time and memory complexity.
6. UVA-specific input/output pitfalls.
7. Three edge cases that could break a naive solution.

Wait for my approval before implementing.
-------------------------------------------------------------------------------

This prevents a common failure mode: the model writes plausible code before
noticing an unusual input format or output requirement.

### Ask for a plan before allowing edits
Press Tab to switch to Plan mode, then ask:

-------------------------------------------------------------------------------
Create a solution plan for this problem. Do not modify files.

The plan must include:

- algorithm,
- data structures,
- overflow risks,
- handling of multiple test cases,
- exact output format,
- a testing strategy.
-------------------------------------------------------------------------------

Once the plan is correct, switch back to Build mode and say:

-------------------------------------------------------------------------------
Implement the approved plan in main.cpp.

Use C++17.
Keep the solution self-contained.
Do not add comments that merely restate the code.
Do not print anything except the required answer.
OpenCode’s documentation specifically recommends planning first for nontrivial tasks and then switching back to Build mode to make the changes.
-------------------------------------------------------------------------------

### Compile and test outside OpenCode
You can ask OpenCode to do this:

-------------------------------------------------------------------------------
Compile main.cpp with:

g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp -o main

Then run it using sample.in. If compilation fails, explain the error and fix
only the necessary code.
-------------------------------------------------------------------------------
For comparing output:

./main < sample.in > actual.out
diff -u expected.out actual.out

The key habit is to make OpenCode show the command and inspect the result yourself. Competitive-programming workflows commonly compile with the same compiler family used by the judge and pipe input through standard input.
GitHub

6. Use brute force and differential testing
   This is where an AI coding agent is particularly useful.

For a problem involving an optimized algorithm, ask OpenCode to create a slow reference solver:

text

Create a separate brute-force reference program named brute.cpp.

It should solve small inputs directly and be obviously correct.
Do not modify main.cpp.
Then ask for a randomized test generator:

text

Create a test-generation script that:

1. generates small random test cases,
2. runs brute.cpp,
3. runs main,
4. compares their outputs,
5. prints the first counterexample.
   A useful prompt is:

text

Audit my solution against a brute-force implementation.

Focus on:

- off-by-one errors,
- duplicate values,
- empty or singleton cases,
- maximum and minimum values,
- integer overflow,
- incorrect reset between test cases,
- formatting and trailing output.
  This is usually more reliable than simply asking, “Is my code correct?”

7. Make OpenCode act as a reviewer
   After you have a working solution, use:

text

Review main.cpp as a strict UVA judge.

Do not rewrite it yet. Report:

1. compile errors,
2. runtime-error risks,
3. wrong-answer cases,
4. time-complexity problems,
5. input parsing problems,
6. output-format problems,
7. any assumptions not guaranteed by the statement.

For every suspected bug, give a concrete counterexample.
Then ask:

text

Use the review to propose a minimal patch. Explain each change before applying it.
If it makes an unwanted change:

text

/undo
OpenCode supports /undo and /redo for reverting or restoring its changes.
opencode.ai

8. Use a separate prompt for a Wrong Answer verdict
   When UVA returns Wrong Answer, provide the exact code, statement, and any known test information:

text

My UVA submission received Wrong Answer.

Problem statement:
[paste statement]

Submitted code:
[paste or reference main.cpp]

Known sample:
[input and expected output]

Analyze likely hidden-test failures. Check especially:

- whether the input can contain blank lines,
- whether the first line is a test count,
- whether ranges are inclusive,
- whether values can arrive in either order,
- whether output requires case numbering,
- whether 32-bit integers are sufficient,
- whether there are extra spaces or blank lines.

Do not make changes until you identify a concrete failure mode.
Avoid telling it only “fix the Wrong Answer.” That encourages random rewrites rather than diagnosis.

9. A good per-problem routine
   Use this sequence for every UVA problem:

text

1. Read the statement manually.
2. Ask OpenCode for a restatement and pitfalls.
3. Develop or request an algorithm explanation.
4. Ask for a correctness argument.
5. Approve a plan.
6. Implement one source file.
7. Compile with warnings.
8. Run sample tests.
9. Add edge cases.
10. Compare with brute force when possible.
11. Review input/output formatting.
12. Submit to UVA.
13. If rejected, diagnose before editing.
14. Record the key idea in notes.md.
    Your notes.md might contain:

markdown

# UVA 100

## Pattern

Range simulation with memoization.

## Main pitfall

The input gives two values in arbitrary order.

## Complexity

Approximately O(maximum value reached) per uncached value.

## Mistake to avoid

Do not use `int` for the intermediate `3n + 1` calculation.
Prompts worth keeping
Explain only:

text

Teach me the key idea without giving code. Ask me questions that help me derive it.
Hint mode:

text

Give me one hint at a time. Do not reveal the complete algorithm unless I ask.
Algorithm critique:

text

Here is my proposed algorithm:
[paste idea]

Find a counterexample if it is incorrect. Otherwise prove why it works and analyze complexity.
Implementation check:

text

Inspect main.cpp against the statement. Do not redesign the algorithm unless it is incorrect.
Final submission check:

text

Perform a final UVA submission audit. Confirm:

- standard input/output only,
- correct entry point,
- no debug output,
- correct handling of all test cases,
- correct newline and spacing,
- no unsupported language features,
- acceptable time and memory complexity.
  The best learning balance is to use Hint mode while learning a topic, Plan mode for unfamiliar problems, and full implementation/debugging assistance only after you can explain the algorithm yourself.
