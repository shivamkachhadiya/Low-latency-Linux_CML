find ~ -type d -name "Linux_CML"
code .

Linux Command Line Shell | C++17, POSIX, Linux System Programming, Process
Management
• Engineered a modular Unix-style command line shell from scratch using low-level POSIX system
calls for direct OS interaction
• Implemented process lifecycle management using fork(), execvp(), wait()/waitpid() for
spawning and controlling child processes
• Built I/O redirection (> , >>) and pipelines (|) using dup2(), pipe(), file descriptor manipulation,
replicating real Linux shell behavior
• Developed built-in commands (cd, pwd, ls, stat, mkdir, rm, cp, touch, cat, history) using
getcwd, chdir, opendir, readdir, stat, open, read, write
• Designed command parser + dispatcher architecture for extensibility and clean separation of
concerns
• Added background execution & job handling, preventing zombie processes via proper wait
handling
• Optimized runtime by minimizing dynamic allocations and using efficient STL containers on hot
paths
• Structured project using CMake, modular compilation, and header abstraction for
maintainability
