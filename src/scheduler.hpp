// src/scheduler.hpp
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include <vector>
#include "task.hpp"
class PriorityQueue {
private:
    std::vector<Task*> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    void insert(Task* task);
    Task* extractMax();
    bool isEmpty();
};
class Scheduler {
private:
    PriorityQueue queue;
public:
    void addTask(Task* task);
    void run();
};
#endif
