sing OpenCode (the open-source terminal AI coding agent) for UVa Online Judge competitive programming gives you a massive speed advantage when structured properly. OpenCode can read your problem statements, run local compiler/test suites using bash, analyze time complexity, and refine code.   Here is a complete workflow for using OpenCode to solve UVa Online Judge problems:1. Directory Structure & House Rules (AGENTS.md)Set up a local template repository. OpenCode reads your project's AGENTS.md file every session to follow your exact coding standards and compilation workflows.   Create a workspace with this structure:Plaintextuva-solutions/
├── AGENTS.md            # House rules for OpenCode
├── template.cpp         # Fast I/O C++ solution starter
└── uva_100/             # Problem workspace
    ├── problem.txt      # Problem description
    ├── input.txt        # Sample inputs
    ├── expected.txt     # Sample outputs
    └── solution.cpp     # Generated code
Create an AGENTS.md file in the root folder with the following contents:Markdown# Competitive Programming Rules (UVa OJ)

1. **Target Language**: C++17 (`g++ -O3 -std=c++17`).
2. **I/O Overhead**: UVa relies heavily on fast I/O (`std::ios_base::sync_with_stdio(false); cin.tie(NULL);`).
3. **Input Handling**: Always handle end-of-file conditions (`while(cin >> x)` or `while(getline(cin, s))`) properly.
4. **Testing Workflow**: Whenever writing or editing `solution.cpp`, run the code against `input.txt` using terminal execution and compare against `expected.txt`.
5. **Limits**: Avoid dynamic allocations inside tight loops; check array bounds for $N \le 10^5$ or larger.
6. Recommended OpenCode Prompting Workflow1.Create the Problem Workspace:Directory setup.Paste the problem description into uva_100/problem.txt alongside sample data in input.txt and expected.txt.2.Run OpenCode in Plan Mode:Algorithm design without immediate code generation.Launch OpenCode inside the directory and ask it to analyze the problem constraints and algorithm complexity before writing code:Bashopencode
"Read uva_100/problem.txt. Analyze the time and space constraints. What data structures and algorithm should we use to avoid Time Limit Exceeded (TLE) on UVa?"3.Generate Solution & Auto-Test:Implementation & validation.Ask OpenCode to implement the code and execute test cases:"Implement uva_100/solution.cpp using template.cpp. Compile it with g++ -O3 -std=c++17 uva_100/solution.cpp -o uva_100/sol and run it with uva_100/sol < uva_100/input.txt. Verify if the output matches uva_100/expected.txt."4.Edge Case Testing:Stress testing for Wrong Answer (WA).Prompt OpenCode to generate potential edge cases:"Generate 3 edge-case inputs in uva_100/stress_in.txt (e.g., max constraints, minimum values, empty inputs) and test solution.cpp against them."3. Best Practices for UVa OJ with OpenCodeFocus AreaTipModel SelectionUse reasoning-heavy models (such as DeepSeek-R1 or GPT-4o/5) for complex dynamic programming, graph, or geometry problems.I/O FormattingUVa OJ is notorious for Presentation Error (PE). Direct OpenCode specifically to account for trailing spaces, blank lines between test cases, and exact output formatting.Local VerificationLeverage OpenCode's ability to execute local bash commands to compile and test code automatically before submitting to UVa.
