// src/scheduler.cpp
#ifdef _WIN32
#include <windows.h>
#define sleep(seconds) Sleep(seconds * 1000)
#else
#include <unistd.h>
#endif
#include "scheduler.hpp"
#include "db_manager.hpp"
#include <ctime>

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent]->priority < heap[index]->priority) {
            std::swap(heap[parent], heap[index]);
            index = parent;
        } else break;
    }
}

void PriorityQueue::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int left = 2 * index + 1, right = 2 * index + 2, largest = index;
        if (left < size && heap[left]->priority > heap[largest]->priority) largest = left;
        if (right < size && heap[right]->priority > heap[largest]->priority) largest = right;
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else break;
    }
}

void PriorityQueue::insert(Task* task) {
    heap.push_back(task);
    heapifyUp(heap.size() - 1);
}

Task* PriorityQueue::extractMax() {
    if (heap.empty()) return nullptr;
    Task* max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) heapifyDown(0);
    return max;
}

bool PriorityQueue::isEmpty() { return heap.empty(); }

void Scheduler::addTask(Task* task) { queue.insert(task); }

void Scheduler::run() {
    DBManager db("C:/Users/KIIT/Desktop/Project/TaskScheduler/data/tasks.db");  // Use absolute path
    while (!queue.isEmpty()) {
        Task* task = queue.extractMax();
        task->state = RUNNING;
        sleep(task->burst_time);
        task->state = COMPLETED;
        time_t now;
        time(&now);
        task->completion_time = std::ctime(&now);
        db.logTask(task);
        delete task;
    }
}
