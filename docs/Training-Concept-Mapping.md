# Linux Sentinel – Training Concept Mapping

## Purpose

This document maps the Linux Sentinel capstone project to the concepts covered during the 20-day Wipro LSP & LDD training program.

The mapping distinguishes between concepts directly implemented in the project and concepts that are represented through architecture, documentation, testing, or future scope.

---

## Module 1 – Computer Architecture: Hardware

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| Computer architecture basics | Hardware/software relationship documented in system architecture | Covered |
| CPU | CPU information obtained from Linux system interfaces | Implemented |
| Memory systems | Memory information obtained from `/proc/meminfo` | Implemented |
| Storage | Filesystem storage statistics | Implemented |
| I/O systems | Linux file/device interface used by the application | Implemented |
| Cache, paging, DMA, FPGA/ASIC | Studied concepts relevant to system architecture | Conceptual |

---

## Module 2 – Computer Architecture: Network

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| TCP/IP | TCP client-server communication | Implemented |
| IP addressing | Localhost `127.0.0.1` used for testing | Implemented |
| Network communication | Linux socket APIs | Implemented |
| Network architecture | Network Manager component | Implemented |
| Other protocols such as HTTP/FTP | Not required by the current prototype | Conceptual |

---

## Module 3 – Linux Operating System and Git

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| Linux command line | Project developed and tested through Linux terminal | Implemented |
| Linux filesystem | `/proc`, filesystem statistics and device files | Implemented |
| Linux permissions | Linux development environment | Covered |
| Shell commands | Used during development and testing | Implemented |
| Git | Project version control | Implemented |
| Git commits/history | Continuous project milestones recorded | Implemented |
| Branching/merging/PRs | Repository workflow documented | Covered |

---

## Module 4 – C++ Programming

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| C++ classes and objects | Modular C++ classes | Implemented |
| Encapsulation | Class-based module design | Implemented |
| File I/O | C++ file streams used for logging/system information | Implemented |
| STL/string/streams | Standard C++ library used throughout application | Implemented |
| OOP | SystemMonitor, DeviceManager, LogManager, NetworkManager | Implemented |
| Makefile and g++ | Root Makefile and g++ compilation | Implemented |
| Data structures | Strings, streams and class-based structures | Implemented |
| Advanced STL/templates | Not required by the current prototype | Conceptual |
| Multithreading | Not required by the current prototype | Future Scope |
| Smart pointers/RTTI | Not required by the current prototype | Future Scope |

---

## Module 5 – Linux System Programming

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| User space / kernel space | Application and character driver architecture | Implemented/Documented |
| System calls | Linux system APIs used | Implemented |
| File descriptors | Device and file operations | Implemented |
| `open()` | LinuxSystem and DeviceManager | Implemented |
| `read()` | LinuxSystem and DeviceManager | Implemented |
| `write()` | DeviceManager and driver interaction | Implemented |
| `close()` | LinuxSystem and DeviceManager | Implemented |
| TCP sockets | Network Manager | Implemented |
| Client-server communication | Local TCP test | Implemented |
| Process management | Process count monitoring | Implemented |
| IPC | Not part of the current prototype | Future Enhancement |
| `fork()` / `exec()` | Not part of the current prototype | Future Enhancement |
| Signals/daemon processes | Not required by current prototype | Future Scope |
| Advanced IPC/shared memory | Not required by current prototype | Future Scope |

---

## Module 6 – Linux Device Drivers

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| Kernel module | Character driver source and kernel module build | Implemented |
| Character device | Linux Sentinel character device | Implemented |
| Device registration | `alloc_chrdev_region()` and `cdev_add()` | Implemented |
| `open()` | Driver file operation | Implemented |
| `read()` | Driver file operation | Implemented |
| `write()` | Driver file operation | Implemented |
| `release()` | Driver file operation | Implemented |
| User/kernel data transfer | `copy_to_user()` / `copy_from_user()` | Implemented |
| Kernel logging | `pr_info()` / `pr_err()` | Implemented |
| Mutex synchronization | Driver mutex | Implemented |
| Device class/sysfs interface | Device class and device creation | Implemented |
| Interrupts | Not required for virtual device | Future Scope |
| Timers/workqueues | Not required for prototype | Future Scope |
| GPIO/I2C/SPI | Physical hardware not used | Future Scope |
| QEMU | Not used in current environment | Future Scope |

### Driver Runtime Limitation

The character driver source was implemented and compiled successfully as a kernel module.

Runtime insertion into the current WSL2 kernel was unsuccessful because of a kernel module format/configuration mismatch.

The limitation is documented honestly and the user-space application safely handles the unavailable device.

---

## Module 7 – Computer Architecture: Software

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| System software | Linux kernel and device-driver layer | Implemented |
| Application software | C++ monitoring application | Implemented |
| Software architecture | Layered modular architecture | Implemented |
| Component separation | Independent monitoring, device, network and logging modules | Implemented |
| Design principles | Modular and maintainable design | Implemented |
| SOLID/DRY/KISS | Applied where appropriate | Covered |
| Microservices | Not required for this local application | Conceptual |
| Docker | Not part of current prototype | Future Enhancement |
| Kubernetes | Not part of current prototype | Future Enhancement |

---

## Module 8 – SDLC and Agile Principles

| Training Concept | Linux Sentinel Coverage | Status |
|---|---|---|
| Requirements gathering | Stage 2 | Implemented |
| Functional requirements | Stage 2 | Implemented |
| Non-functional requirements | Stage 2 | Implemented |
| Project planning | Stage 2 | Implemented |
| System design | Stage 3 | Implemented |
| Architecture | Stage 3 | Implemented |
| UML class diagram | Stage 3 | Implemented |
| UML sequence diagram | Stage 3 | Implemented |
| UML state machine | Stage 3 | Implemented |
| Implementation | Stage 4 | Implemented |
| Testing | Stage 5 | Implemented |
| Final delivery | Stage 6 | Implemented |
| Git progress tracking | Throughout development | Implemented |

---

## Module 9 – Capstone Project

The Linux Sentinel project follows the required six-stage capstone process:

1. Project Introduction
2. Requirements and Development Plan
3. System Design and Architecture
4. Initial Implementation and Prototype
5. Testing, Integration and Improvement
6. Final Implementation and Presentation

Each stage has corresponding documentation and Git version history.

---

## Overall Training Coverage

Linux Sentinel directly demonstrates the most relevant implementation-oriented concepts from the training:

- Linux
- C++
- Git
- Computer architecture
- TCP/IP networking
- Linux system programming
- Linux character device drivers
- Kernel/user-space interaction
- Synchronization
- Software architecture
- UML
- SDLC
- Testing
- Version control

Concepts that are not directly required for the current virtual-device prototype are clearly identified as conceptual or future enhancements rather than being falsely presented as implemented.
