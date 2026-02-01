# 🚀 Low-latency-File-eXplorer

### High-Performance Linux CLI File Explorer & Mini Shell in Modern C++

A high-performance Linux command-line file explorer and mini shell focused on systems programming. By leveraging direct POSIX/Linux system calls, it provides deterministic, low-latency, and high-speed operations.

---

## 📌 Project Overview

Built for speed and reliability, this project emphasizes:

* **Clean Modular Architecture:** Clear separation of components for maintainability.
* **Zero Abstraction Overhead:** Direct communication with the OS.
* **Low Memory Footprint:** Minimizing heap allocations to reduce latency.
* **Deterministic Performance:** Real-world systems engineering practices for predictable execution.

---

## 🛠 Tech Stack & Tools

| Tool | Purpose |
| :--- | :--- |
| **WSL (Ubuntu 22.04)** | Linux environment on Windows |
| **g++** | Industry-standard C++ compiler |
| **CMake** | Modern build system for scalable projects |
| **Git** | Version control (excluding binaries) |
| **VS Code Remote-WSL** | IDE with seamless Linux integration |
| **perf / Valgrind** | Performance profiling and memory debugging |

---

## 🧠 Memory Strategy: Stack vs. Heap

To achieve low-latency performance, **stack allocation** is prioritized over heap allocation whenever possible.

| Memory Type | Speed | Allocation | Lifetime |
| :--- | :--- | :--- | :--- |
| **Stack** | ⚡ Very Fast | Automatic | Local Scope |
| **Heap** | 🐢 Slower | Manual (`new` / `malloc`) | Explicit Control |

**Why stack?**  
A stack buffer (e.g., `char buffer[4096];`) avoids the complexity of heap management, involves no `malloc` overhead, and guarantees predictable latency—essential for systems-level tools.

---

## 🔹 Core System Call: `getcwd()`

Getting the current working directory is a foundational building block for the shell.

### Signature
```c
char* getcwd(char* buf, size_t size);




How It Works

Your program: Allocates a fixed-size buffer on the stack.

libc: Wraps the request and triggers a kernel syscall.

Kernel: Retrieves the current path and writes it into your buffer.

Copy: Kernel → User space.

Return: Returns the pointer to the buffer, or NULL on failure.

Memory Visualization:
If the path is /home/kshivam, the buffer contains:

/home/kshivam\0


The \0 (null terminator) marks the end of the string for C-style functions.

Example Implementation (C++)
#include <unistd.h>
#include <linux/limits.h>
#include <iostream>

void print_directory() {
    char buffer[PATH_MAX]; // Stack buffer
    
    if(getcwd(buffer, sizeof(buffer)) != nullptr) {
        std::cout << "Current Path: " << buffer << "\n";
    } else {
        perror("getcwd"); // Standard error reporting
    }
}

❓ Quick Reference for Systems Interviews

Q: Why use stack buffers instead of std::string?
A: Stack allocation is deterministic and avoids the unpredictable latency of heap operations.

Q: What is PATH_MAX?
A: A Linux constant representing the maximum possible length of a file path (usually 4096 bytes).

Q: Why avoid committing binaries to Git?
A: Binaries are platform-dependent and unnecessarily bloat the repository.

Q: What happens if the buffer provided to getcwd() is too small?
A: It returns NULL and sets errno to ERANGE.

🚀 Future Roadmap

 Implement ls functionality using opendir() and readdir().

 Add support for piping (|) between commands.

 Implement custom signal handling for SIGINT.

Developed as a deep dive into Linux systems programming, focusing on performance, memory efficiency, and deterministic behavior.


---

If you want, I can also create a **slightly more “modern GitHub-ready” version** with **badges, code highlighting, and collapsible sections** so it looks super polished for open-source.  

Do you want me to do that too?
