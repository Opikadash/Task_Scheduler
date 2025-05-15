#include "scheduler.hpp"
#include <iostream>
int main() {
    Scheduler scheduler;
    std::string command;
    while (true) {
        std::cout << "Enter command (add/run/exit): ";
        std::cin >> command;
        if (command == "add") {
            int id, prio, burst;
            std::cout << "Enter task_id, priority, burst_time: ";
            std::cin >> id >> prio >> burst;
            Task* task = new Task(id, prio, burst);
            scheduler.addTask(task);
        } else if (command == "run") {
            scheduler.run();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command\n";
        }
    }
    return 0;
}
