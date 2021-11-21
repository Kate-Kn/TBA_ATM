#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <QSql>
#include <QSqlDatabase>
#include <string>
using namespace std;

class DB {
private:
    const vector<string> credentials(const char* cfg_filename) const;
public:
    DB() {};
    ~DB() {};
    void connect() const;
};
#endif // DB_CONNECTION_H
