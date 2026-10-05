# Stage 2 – Project Requirements and Development Plan

## 2.1 Functional Requirements

The Linux Sentinel system shall:

1. Display CPU information.
2. Display memory information.
3. Display storage information.
4. Display the number of running processes.
5. Access Linux system resources using system calls.
6. Establish TCP/IP client-server communication.
7. Provide device status information.
8. Support device commands through the device management layer.
9. Record important application events in a log file.
10. Provide an interactive command-line menu.
11. Handle unavailable devices without terminating the application.
12. Support compilation through a Makefile.

## 2.2 Non-Functional Requirements

### Performance

The application should provide system information with minimal processing overhead.

### Reliability

The application should handle unavailable system resources and devices gracefully.

### Maintainability

The application should use separate modules for system monitoring, device management, networking, and logging.

### Portability

The application should be designed for Linux-based environments.

### Security

System resources and device interfaces should be accessed using appropriate Linux permissions and system interfaces.

### Usability

The command-line interface should provide clear menu options and readable output.

## 2.3 Product Requirements Document (PRD)

### Product Name

Linux Sentinel

### Product Type

Linux-based system and device health monitoring application.

### Target Users

- Linux system administrators
- Embedded system developers
- Linux learners
- Technical support and monitoring teams

### Product Goal

To provide a simple command-line application that demonstrates system monitoring, Linux system programming, network communication, and device management.

## 2.4 Project Modules and Features

### Module 1 – System Monitoring

Features:

- CPU information
- Memory information
- Storage information
- Process monitoring

### Module 2 – Linux System Programming

Features:

- File descriptor operations
- Linux system calls
- System file access

### Module 3 – Network Communication

Features:

- TCP server
- TCP client
- Localhost communication
- Network status information

### Module 4 – Device Management

Features:

- Device file access
- Device status reading
- Device command handling
- Graceful unavailable-device handling

### Module 5 – Character Device Driver

Features:

- Character device registration
- Open operation
- Read operation
- Write operation
- Release operation
- Mutex-based synchronization
- Device status management

### Module 6 – Logging

Features:

- Application startup logging
- System monitoring logging
- Device event logging
- Application exit logging

### Module 7 – Command-Line Interface

Features:

- System Health
- Device Status
- Network Status
- View Logs
- Exit

## 2.5 Project Deliverables

The project deliverables include:

- C++ source code
- Linux character device driver source
- Header files
- Makefiles
- Network test programs
- Testing documentation
- System architecture documentation
- UML diagrams
- README.md
- Git repository
- Final project demonstration

## 2.6 Development Plan and Timeline

The project follows the six-stage capstone process:

| Stage | Activity |
|---|---|
| Stage 1 | Project Introduction |
| Stage 2 | Requirements and Development Plan |
| Stage 3 | System Design and Architecture |
| Stage 4 | Initial Implementation and Prototype |
| Stage 5 | Testing, Integration and Improvement |
| Stage 6 | Final Implementation and Presentation |

## 2.7 Development Approach

The project follows an incremental development approach.

The core application is developed first, followed by system programming, networking, device management, driver implementation, logging, integration, testing, and final documentation.

Git is used to maintain version history and track project progress.

## 2.8 Development Environment and Tools

| Tool | Purpose |
|---|---|
| Ubuntu on WSL2 | Linux development environment |
| G++ | C++ compilation |
| GNU Make | Build automation |
| GDB | Debugging |
| Git | Version control |
| Linux system APIs | System interaction |
| TCP sockets | Network communication |

## 2.9 Project Constraints

The project follows the faculty requirements:

- Development is performed on Linux.
- C and C++ are used for implementation.
- Python and Java are not used.
- Linux device driver concepts are incorporated.
- The project is based on software and hardware architecture concepts.
- Source code and documentation are maintained using Git.
