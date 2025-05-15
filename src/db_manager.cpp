#include "db_manager.hpp"
#include <iostream>

DBManager::DBManager(const std::string& db_path) {
    if (sqlite3_open(db_path.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        std::cout << "Database opened successfully: " << db_path << std::endl;
        initDB();
    }
}

DBManager::~DBManager() {
    if (db) {
        sqlite3_close(db);
    }
}

void DBManager::initDB() {
    if (!db) {
        std::cerr << "Database not initialized, cannot create table" << std::endl;
        return;
    }
    const char* sql = "CREATE TABLE IF NOT EXISTS tasks (task_id INTEGER PRIMARY KEY, priority INTEGER, burst_time INTEGER, completion_time TEXT);";
    char* errMsg = 0;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table 'tasks' created successfully" << std::endl;
    }
}

void DBManager::logTask(Task* task) {
    if (!db) {
        std::cerr << "Database not initialized, cannot log task" << std::endl;
        return;
    }
    std::string sql = "INSERT INTO tasks (task_id, priority, burst_time, completion_time) VALUES (" +
                      std::to_string(task->task_id) + ", " +
                      std::to_string(task->priority) + ", " +
                      std::to_string(task->burst_time) + ", '" +
                      task->completion_time + "');";
    char* errMsg = 0;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Task logged successfully: ID=" << task->task_id << std::endl;
    }
}
