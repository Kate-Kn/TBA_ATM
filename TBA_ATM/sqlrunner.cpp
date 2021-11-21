#include "sqlrunner.h"

SqlRunner::SqlRunner(const char* path): _script_path(path) {}

void SqlRunner::execute(const char *params) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list();
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            query.prepare(queryTxt);
            query.bindValue(":passport_num", params);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}

const QStringList SqlRunner::file_to_list() {
   QFile script(this->_script_path);
   QStringList scriptQueries;
   if (script.open(QIODevice::ReadOnly)) {
       scriptQueries = QTextStream(&script).readAll().split(';');
   }
   return scriptQueries;
}
