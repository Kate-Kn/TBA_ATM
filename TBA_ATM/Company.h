#ifndef COMPANY_H
#define COMPANY_H

#include <QString>

using namespace std;

class Company{
private:
    QString _title;
    QString _description;
public:
    Company(QString title, QString descroption):
        _title(title), _description(descroption)
    { return; }
    Company(){ return; }
    Company(const Company& company):
        _title(company.title()), _description(company.description())
    { return; }
    ~Company(){ return; }
    const QString& title() const { return _title; }
    const QString& description() const { return _description; }
    void title(const QString& newTitle) { _title = newTitle; return; }
    void description(const QString&  newDescription) { _description = newDescription; return; }
};

#endif
