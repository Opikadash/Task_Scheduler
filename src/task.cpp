// src/task.cpp
#include "task.hpp"
Task::Task(int id, int prio, int burst) : task_id(id), priority(prio), burst_time(burst), state(READY) {}
