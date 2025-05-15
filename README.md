# Task Scheduler MVP
A C++ task scheduler using a priority queue and SQLite logging.

## Features
- Non-preemptive priority scheduling.
- CLI to add/run tasks.
- SQLite logs for task completion.

## Build
```powershell
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
.\scheduler.exe
