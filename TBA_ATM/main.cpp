#include "mainwindow.h"
#include "db_connection.h"
#include "sqlrunner.h"
#include <QApplication>
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    DB *database = new DB();
    database->connect();
    SqlRunner rnn;
    qDebug() << rnn.checkCard("1234", "1234");
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,345);
    w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    w.show();

    return a.exec();
}
