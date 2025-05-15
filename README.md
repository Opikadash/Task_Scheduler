# Task Scheduler (Priority Queue)
A C++ task scheduler that implements non-preemptive priority scheduling, manages tasks using a priority queue, and logs task completion details to a SQLite database.

## Features

Non-Preemptive Priority Scheduling: Tasks are executed based on priority (highest first) without interruption.
Command-Line Interface (CLI): Add tasks, run the scheduler, and exit the program via simple commands.
SQLite Logging: Task details (ID, priority, burst time, completion time) are logged to a SQLite database (data/tasks.db).

## Build
```powershell
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
.\scheduler.exe

## Prerequisites

C++17 Compiler: MinGW (used in this project) or any compatible compiler.
CMake: For building the project.
SQLite: The project includes SQLite via the amalgamation source (sqlite3.c).

## Directory Structure

src/: Source files (main.cpp, task.cpp, scheduler.cpp, db_manager.cpp).
data/: Directory for the SQLite database (tasks.db).
build/: Build directory for compiled files.

## Build Instructions

Clone the repository:git clone https://github.com/Opikadash/Task_Scheduler.git
cd Task_Scheduler


Create a build directory:mkdir build
cd build


Generate build files with CMake (using MinGW Makefiles):cmake .. -G "MinGW Makefiles"


Build the project:cmake --build .


Run the executable:.\scheduler.exe



## Usage
The program provides a CLI to interact with the scheduler:

Add a Task: add <task_id> <priority> <burst_time>
Example: add 1 10 2 (Task ID: 1, Priority: 10, Burst Time: 2 seconds).


Run the Scheduler: run
Executes all tasks in order of priority (highest first).


## Exit the Program: exit

Example Interaction
Enter command (add/run/exit): add 1 10 2
Enter command (add/run/exit): add 2 5 3
Enter command (add/run/exit): run
Enter command (add/run/exit): exit


Tasks will be logged to data/tasks.db. To view:sqlite3 C:\Users\KIIT\Desktop\Project\TaskScheduler\data\tasks.db "SELECT * FROM tasks;"


## Database Schema
The tasks.db database contains a single table tasks with the following schema:

task_id (INTEGER, PRIMARY KEY): Unique task identifier.
priority (INTEGER): Task priority (higher values indicate higher priority).
burst_time (INTEGER): Execution time in seconds.
completion_time (TEXT): Timestamp when the task completed (e.g., "Thu May 15 09:50:00 2025").

## Advantages

The project uses the SQLite amalgamation (sqlite3.c) for simplicity, so no external SQLite installation is required.
The scheduler is non-preemptive: once a task starts, it runs to completion.


