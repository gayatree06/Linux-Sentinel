# Linux Sentinel

## A C++-Based System and Device Health Monitoring System

Linux Sentinel is an individual capstone project developed as part of the Wipro LSP & LDD 20-Day Training Program.

The project demonstrates Linux system programming, C++, TCP/IP networking, Linux character device driver concepts, software architecture, Git-based development, and system health monitoring.

## 1. Project Objective

The objective of Linux Sentinel is to provide a command-line based system and device health monitoring application for Linux environments.

The application collects system information, provides device management functionality, demonstrates TCP/IP communication, maintains application logs, and provides an interface for interacting with a Linux character device.

## 2. Key Features

- CPU information monitoring
- Memory information monitoring
- Storage information monitoring
- Running process monitoring
- Linux system file access using system calls
- TCP/IP client-server communication
- Linux character device driver implementation
- Device status management
- Application event logging
- Interactive command-line interface
- Makefile-based compilation
- Git version control

## 3. System Architecture

```text
User
  |
  v
C++ Command-Line Application
  |
  +--------------------+
  |                    |
  v                    v
System Monitoring    Device Manager
  |                    |
  v                    v
Linux System APIs    Character Device
  |                    |
  |                    v
  |                Linux Kernel
  |                    |
  |                    v
  |                Virtual Device
  |
  v
/proc and Linux Filesystem

C++ Application
       |
       v
Network Manager
       |
       v
TCP/IP Communication
       |
       v
Local Client/Server
