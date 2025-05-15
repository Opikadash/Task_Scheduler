# Task Scheduler 

A C++ implementation of a Task Scheduler using a priority queue for non-preemptive scheduling, with task logging to a SQLite database via a command-line interface (CLI).

## Overview
The Task Scheduler MVP is a lightweight C++ application designed to manage tasks based on priority using a max-heap priority queue. Tasks are executed non-preemptively, and their completion details are stored in a SQLite database. This project serves as a proof-of-concept for scheduling algorithms and database integration.

## Features
- **Non-Preemptive Priority Scheduling**: Tasks are executed in order of priority (highest first) without interruption.
- **CLI Interface**: Add tasks, run the scheduler, and exit using simple commands.
- **SQLite Persistence**: Logs task details (ID, priority, burst time, completion time) to a database.
- **Cross-Platform Build**: Uses CMake for portability (tested with MinGW).

## Prerequisites
- **C++17 Compiler**: MinGW (recommended) or GCC/Clang.
- **CMake**: Version 3.10 or higher for building the project.
- **Git**: For cloning the repository.

## Installation

### Clone the Repository
Clone the repository to your local machine:
```bash
git clone https://github.com/Opikadash/Task_Scheduler.git
cd Task_Scheduler
```

### Create Build Directory
Create a build directory and navigate to it:
```bash
mkdir build
cd build
```

### Generate Build Files
Generate build files with CMake:
```bash
cmake .. -G "MinGW Makefiles"
```

### Build the Project
Build the project:
```bash
cmake --build .
```

### Run the Executable
Run the executable:
```bash
./scheduler.exe  # Windows
# or
./scheduler      # Linux/Mac (if compiled accordingly)
```

## Usage
Interact with the scheduler via the CLI:

### Add a Task
Use the `add` command to add a task with a task ID, priority, and burst time:
- **Syntax**: `add <task_id> <priority> <burst_time>`
- **Example**: `add 1 10 2` (ID 1, priority 10, 2-second burst)

### Run the Scheduler
Use the `run` command to execute all tasks in priority order:
- **Syntax**: `run`

### Exit the Program
Use the `exit` command to terminate the program:
- **Syntax**: `exit`

### Example Interaction
```plaintext
Enter command (add/run/exit): add 1 10 2
Enter command (add/run/exit): add 2 5 3
Enter command (add/run/exit): run
Enter command (add/run/exit): exit
```

### View Task Logs
Tasks are logged to `data/tasks.db`. To view the log:
```bash
sqlite3 data/tasks.db "SELECT * FROM tasks;"
```

## Project Structure
```
TaskScheduler/
├── src/
│   ├── main.cpp           # Main entry point with CLI
│   ├── task.hpp           # Task class definition
│   ├── task.cpp           # Task class implementation
│   ├── scheduler.hpp      # Scheduler and PriorityQueue definitions
│   ├── scheduler.cpp      # Scheduler and PriorityQueue implementations
│   ├── db_manager.hpp     # Database manager definition
│   ├── db_manager.cpp     # Database manager implementation
├── data/                  # Directory for tasks.db (SQLite database)
├── .gitignore             # Git ignore file
├── CMakeLists.txt         # CMake configuration
└── README.md              # This file
```

## Database Schema
The `tasks.db` SQLite database contains a `tasks` table with:

| Column            | Type    | Description                          |
|-------------------|---------|--------------------------------------|
| `task_id`         | INTEGER | Primary key, unique task identifier  |
| `priority`        | INTEGER | Task priority (higher = higher priority) |
| `burst_time`      | INTEGER | Execution time in seconds            |
| `completion_time` | TEXT    | Timestamp of task completion         |



## Acknowledgments
- Inspired by operating system scheduling concepts.
- Utilizes SQLite amalgamation for embedded database support.
