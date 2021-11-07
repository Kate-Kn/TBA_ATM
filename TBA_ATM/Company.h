#ifndef COMPANY_H
#define COMPANY_H
#include <string>
using namespace std;

class Company{
private:
    string _title;
    string _description;
public:
    Company(string title, string descroption):
        _title(title), _description(descroption)
    { return; }
    Company(const Company& company):
        _title(company.title()), _description(company.description())
    { return; }
    ~Company(){ return; }
    string title() const { return _title; }
    string description() const { return _description; }
};

#endif
