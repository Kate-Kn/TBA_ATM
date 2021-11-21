#include "mainwindow.h"
#include "db_connection.h"
#include "sqlrunner.h"
#include <QApplication>
#include <QtCore/QCoreApplication>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    DB *database = new DB();
    database->connect();
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,345);
    w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    w.show();

    return a.exec();
}
