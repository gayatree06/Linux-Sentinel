# Stage 5 – Testing, Integration and Improvement

## 5.1 Stage Objective

The objective of Stage 5 is to test the Linux Sentinel application, verify the integration of its major modules, identify issues, and document the results.

## 5.2 Testing Approach

The project was tested using build testing, functional testing, system monitoring testing, Linux system programming testing, network testing, device management testing, logging testing, and integrated CLI testing.

## 5.3 Test Cases

| Test ID | Test Case | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| TC-01 | Build project using Makefile | Project compiles successfully | Compilation successful | PASS |
| TC-02 | Launch Linux Sentinel | Application starts and displays menu | Menu displayed successfully | PASS |
| TC-03 | System Health | CPU, memory, storage and process information displayed | Information displayed successfully | PASS |
| TC-04 | Linux system file access | Linux system information can be accessed | System information accessed successfully | PASS |
| TC-05 | TCP/IP networking | Client-server communication works | TCP communication tested successfully | PASS |
| TC-06 | Device Manager | Application handles unavailable device safely | Unavailable device handled correctly | PASS |
| TC-07 | Logging | Application events are written to log file | Log file generated successfully | PASS |
| TC-08 | CLI integration | Menu options execute correctly | Menu functions executed successfully | PASS |
| TC-09 | Exit handling | Application exits without error | Application exited successfully | PASS |

## 5.4 Build Testing

The project was built using the root Makefile.

Command:

```bash
make clean
make
