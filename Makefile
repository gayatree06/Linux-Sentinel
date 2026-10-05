CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -Iinclude

SOURCES = src/main.cpp \
          src/SystemMonitor.cpp \
          src/LinuxSystem.cpp \
          src/DeviceManager.cpp \
          src/LogManager.cpp

TARGET = linux_sentinel

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
