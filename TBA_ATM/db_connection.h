#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <QSql>
#include <QSqlDatabase>
class DB {
public:
    DB() {};
    ~DB() {};
    void connect();
};
#endif // DB_CONNECTION_H
