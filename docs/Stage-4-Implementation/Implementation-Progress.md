# Stage 4 – Initial Implementation & Prototype

## 4.1 Stage Objective

The objective of Stage 4 is to begin the implementation of Linux Sentinel, develop the core modules progressively, create an initial working prototype, integrate the major components, and record development progress, issues, solutions, testing activities, and evidence.

## 4.2 Development Environment Preparation

The Linux development environment was prepared using Ubuntu 24.04 LTS running under WSL2. The Linux kernel was verified using the `uname -a` command.

The required development tools were installed and verified:

- GNU C++ Compiler (G++) 13.3.0
- Git 2.43.0
- GDB 15.1
- Build Essential

## 4.3 Project Workspace

The Linux Sentinel development workspace was created at:

`/home/gayatree/Linux-Sentinel`

The initial project structure was created with dedicated directories for source code, headers, device-driver code, networking, testing, documentation, diagrams, and scripts.

## 4.4 Version Control Setup

A Git repository was initialized for the Linux Sentinel project.

Git user identity was configured and the initial project foundation was committed successfully.

Initial commit:

`c998c33 – Initial Linux Sentinel project structure`

## 4.5 Current Progress

Completed:

- Linux development environment prepared
- C++ compiler installed and verified
- Git installed and verified
- GDB installed and verified
- Linux Sentinel workspace created
- Initial project directory structure created
- Git repository initialized
- Initial README.md created
- Initial .gitignore created
- Stage 4 documentation folder created
- Initial Git baseline commit completed

## 4.6 Issues and Solutions

### Issue 1 – WSL2 Environment Initialization

The initial WSL2 environment could not start because a required Windows virtualization feature was disabled.

### Solution

The Windows Hypervisor Platform feature was enabled and the system was restarted. Ubuntu 24.04 LTS was then successfully initialized under WSL2.

### Result

The Linux development environment became operational and was verified using the Linux kernel information command.

## 4.7 Evidence

The following evidence has been captured during the development setup:

- Ubuntu/Linux environment verification
- C++ compiler verification
- Git verification
- GDB verification
- Initial Linux project workspace
- Initial project structure
- Git repository initialization
- Initial Git commit

## 4.8 Next Planned Activity

The next activity is to develop the initial C++ application skeleton for Linux Sentinel. The prototype will then be progressively extended with system monitoring, Linux system programming, device-driver communication, networking, logging, testing, and integration.

## 4.9 Stage 4 Progress Principle

Development will follow a progressive implementation approach. Each major implementation milestone will be tested, documented, supported by appropriate progress evidence, and committed to Git before proceeding to the next major activity.
## 4.10 Initial C++ Prototype

The initial C++ prototype of Linux Sentinel was implemented and successfully executed on the Ubuntu Linux development environment.

The prototype includes the main application entry point and displays the project identity and startup confirmation message.

The source file is:

`src/main.cpp`

The application was compiled using G++ with C++17, warning checks, and debug information. The resulting executable was successfully executed on Linux.

### Result

The initial working C++ prototype was successfully created and verified.

### Evidence

- Successful C++ compilation
- Successful Linux Sentinel prototype execution
- Git commit: `447fdeb – Add initial C++ prototype`

## 4.11 CPU Monitoring Implementation

The SystemMonitor module was integrated with the Linux Sentinel main application.

The `SystemMonitor::getCpuInfo()` function reads CPU information from the Linux `/proc/cpuinfo` virtual filesystem and returns the CPU model information to the main application.

### Implementation

- Created `include/SystemMonitor.h`
- Created `src/SystemMonitor.cpp`
- Implemented the `SystemMonitor` class
- Added CPU information retrieval through `/proc/cpuinfo`
- Integrated `SystemMonitor` with `src/main.cpp`
- Compiled the integrated application successfully
- Executed the application successfully on Ubuntu Linux

### Result

Linux Sentinel successfully displayed the actual CPU model information at runtime.

### Evidence

- Successful SystemMonitor module compilation
- Successful integrated application compilation
- Successful CPU information runtime output

## 4.12 Memory Monitoring Implementation

The SystemMonitor module was extended to collect memory information from the Linux environment.

The `SystemMonitor::getMemoryInfo()` function reads the Linux `/proc/meminfo` virtual filesystem and retrieves the total and available memory values.

### Implementation

- Added `getMemoryInfo()` to `SystemMonitor`
- Implemented memory information retrieval using `/proc/meminfo`
- Integrated memory monitoring with `src/main.cpp`
- Compiled the updated application successfully
- Executed the application successfully on Ubuntu Linux

### Result

Linux Sentinel successfully displayed the total and available memory information at runtime.

### Evidence

- Successful SystemMonitor compilation
- Successful integrated application compilation
- Successful memory information runtime output

## 4.13 Storage Monitoring Implementation

The SystemMonitor module was extended to collect storage information from the Linux filesystem.

The `SystemMonitor::getStorageInfo()` function uses the Linux `statvfs()` filesystem interface to calculate total, used, and available storage space for the root filesystem.

### Implementation

- Added `getStorageInfo()` to `SystemMonitor`
- Added the Linux `statvfs()` interface
- Implemented total, used, and available storage calculation
- Integrated storage monitoring with `src/main.cpp`
- Compiled the updated application successfully
- Executed the application successfully on Ubuntu Linux

### Result

Linux Sentinel successfully displayed total, used, and available storage information at runtime.

### Evidence

- Successful SystemMonitor compilation
- Successful integrated application compilation
- Successful storage information runtime output

## 4.14 Process Monitoring Implementation

Process monitoring was implemented as the next system-monitoring capability of Linux Sentinel.

The `SystemMonitor` class was extended with a `getProcessInfo()` function. The implementation uses the Linux `/proc` filesystem to identify numeric process directories representing active process IDs (PIDs).

The application counts the identified process directories and displays the current number of running processes.

### Implementation Details

- Added `getProcessInfo()` to `SystemMonitor`
- Used the Linux `/proc` filesystem
- Identified numeric process directories as process IDs
- Counted the currently running processes
- Integrated process information into the main Linux Sentinel application
- Successfully compiled and executed the application

### Verification

The application successfully displayed:

`Running Processes: 24`

The process count represents the running processes detected in the current Linux environment and may vary during different executions.

### Git Version Control

The Process Monitoring implementation was committed to Git:

`8839517 – Implement process monitoring`

### Evidence

A screenshot of the successful Linux Sentinel execution showing CPU, memory, storage, and process information was captured as implementation evidence.

### Training Concepts Demonstrated

- Linux process concepts
- Linux `/proc` filesystem
- C++17 filesystem functionality
- System monitoring
- C++ string and iteration operations

### Next Planned Activity

The next activity is to continue implementing the Linux system programming and device-management components of Linux Sentinel.

## 4.15 Linux System Programming Implementation

Linux system programming functionality was implemented as part of the Linux Sentinel application.

A dedicated `LinuxSystem` class was created to demonstrate interaction between the C++ user-space application and Linux system interfaces.

The implementation uses Linux system calls to open, read, and close a system file. The `/proc/uptime` interface was selected as the initial system-information source.

### Implementation Details

- Created `LinuxSystem` class
- Implemented `readSystemFile()` function
- Used the Linux `open()` system call
- Used the Linux `read()` system call
- Used the Linux `close()` system call
- Used file descriptors for system-file access
- Integrated the module into the main Linux Sentinel application
- Successfully compiled and executed the application

### Verification

Linux Sentinel successfully read `/proc/uptime` and displayed the system uptime information during execution.

### Training Concepts Demonstrated

- Linux System Programming
- System calls
- File descriptors
- User-space interaction with Linux system interfaces
- Linux `/proc` filesystem

### Git Version Control

The Linux System Programming implementation was committed to Git as a separate development milestone.

### Evidence

A screenshot of the successful Linux Sentinel execution showing the Linux System Information output was captured as implementation evidence.

### Next Planned Activity

The next activity is to implement the networking component using TCP/IP communication, followed by the Linux character device driver and user-space device communication.

## 4.16 TCP/IP Networking Implementation

TCP/IP networking functionality was implemented as part of Linux Sentinel.

A dedicated `NetworkManager` class was created to provide TCP server and client functionality using Linux socket APIs.

### Implementation Details

- Created `NetworkManager` class
- Implemented TCP server functionality
- Created a TCP socket using `socket()`
- Configured the server using `bind()`
- Enabled connection listening using `listen()`
- Accepted client connections using `accept()`
- Implemented TCP client connection using `connect()`
- Implemented server-to-client communication using `send()`
- Implemented client response reception using `recv()`
- Added basic network error handling
- Created separate TCP server and client test programs

### Verification

The TCP server was successfully started and a client successfully connected to it.

The server returned the following response to the client:

`DEVICE_OK`

The client successfully displayed the server response, confirming TCP client-server communication.

### Training Concepts Demonstrated

- TCP/IP networking
- Client-server architecture
- Linux socket programming
- TCP connection establishment
- Data transmission and reception
- Network error handling

### Git Version Control

The TCP networking implementation was committed to Git:

`8875283 – Implement TCP networking`

### Evidence

A screenshot showing the successful TCP client connection and `DEVICE_OK` server response was captured as Stage 4 implementation evidence.

### Next Planned Activity

The next major activity is implementation of the Linux character device driver and communication between the user-space C++ application and the Linux device driver.
