# Stage 3 – System Design and Architecture

## 3.1 System Architecture Overview

Linux Sentinel follows a layered architecture in which the user interacts with a C++ command-line application. The application communicates with Linux system interfaces, the device management layer, and the network communication layer.

The character device driver provides the interface between the user-space application and the Linux kernel.

## 3.2 Major Components and Responsibilities

### User

The user interacts with the system through the command-line interface.

### CLI Application

The C++ CLI application provides menu options and coordinates the different project modules.

### System Monitoring

The System Monitoring module collects:

- CPU information
- Memory information
- Storage information
- Running process information

### Linux System Programming

The Linux System Programming module provides access to Linux system resources using file descriptors and system calls.

### Device Manager

The Device Manager provides user-space interaction with the Linux character device.

### Network Manager

The Network Manager handles TCP/IP client-server communication.

### Log Manager

The Log Manager records important application events in a log file.

### Linux Character Driver

The character driver provides device operations such as open, read, write, and release and uses mutex synchronization.

### Linux Kernel

The Linux kernel provides the underlying operating system and device management functionality.

## 3.3 Data Flow

The major data flow is:

```text
User
  |
  v
C++ CLI Application
  |
  +------------------+------------------+
  |                  |                  |
  v                  v                  v
System Monitor   Device Manager    Network Manager
  |                  |                  |
  v                  v                  v
Linux System     Character Device    TCP/IP Socket
Interfaces          Driver              |
  |                  |                  |
  v                  v                  v
/proc and FS      Linux Kernel      TCP Server/Client
