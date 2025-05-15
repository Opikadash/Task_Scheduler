// src/db_manager.hpp
#ifndef DB_MANAGER_HPP
#define DB_MANAGER_HPP
#include <sqlite3.h>
#include "task.hpp"
class DBManager {
private:
    sqlite3* db;
public:
    DBManager(const std::string& db_path);
    ~DBManager();
    void initDB();
    void logTask(Task* task);
};
#endif
