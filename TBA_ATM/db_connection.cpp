#include <QDebug>
#include "db_connection.h"

void DB::connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setHostName("localhost");
       db.setDatabaseName("atm");
       db.setUserName("root");
       db.setPassword("12345");
       bool ok = db.open();
       qDebug() << ok;
}
