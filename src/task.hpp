// src/task.hpp
#ifndef TASK_HPP
#define TASK_HPP
#include <string>
enum TaskState { READY, RUNNING, COMPLETED };
class Task {
public:
    int task_id, priority, burst_time;
    std::string completion_time;
    TaskState state;
    Task(int id, int prio, int burst);
};
#endif
