#include <QDebug>
#include <QFile>
#include "db_connection.h"
#include <iostream>
#include <fstream>
#include <algorithm>

const vector<string> DB::credentials(const char* cfg_filename) const {
   vector<string> creds = {};
   QFile inputFile(cfg_filename);
   if (inputFile.open(QIODevice::ReadOnly))
   {
      QTextStream in(&inputFile);
      while (!in.atEnd())
      {
         QString line = in.readLine();
          auto delimiterPos = line.indexOf("=");
          QString name = line.left(delimiterPos);
          QString value = line.mid(delimiterPos + 1, line.length() - 1);
          creds.push_back(value.toStdString());
      }
      inputFile.close();
   }
    return creds;
}

void DB::connect() const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
       vector<string> creds = this->credentials("D:/TBA_ATM/TBA_ATM/db_config.txt");
       QString host_name, db_name, user_name, pass;
       user_name = QString::fromStdString(creds.at(0));
       db_name = QString::fromStdString(creds.at(1));
       host_name = QString::fromStdString(creds.at(2));
       pass = QString::fromStdString(creds.at(3));

       db.setHostName(host_name);
       db.setDatabaseName(db_name);
       db.setUserName(user_name);
       db.setPassword(pass);
       bool ok = db.open();
       qDebug() << ok;
}
