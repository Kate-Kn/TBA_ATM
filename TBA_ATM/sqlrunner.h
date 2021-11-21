#ifndef SQLRUNNER_H
#define SQLRUNNER_H
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <QString>
using namespace std;

class SqlRunner
{
private:
    const QString _script_path;
public:
    SqlRunner(const char* path);
    ~SqlRunner(){}
    const QStringList file_to_list();
    void execute(const char* params={});
};

#endif // SQLRUNNER_H
