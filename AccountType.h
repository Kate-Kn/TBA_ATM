#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H
#include <string>
using namespace std;

class AccountType{
private:
    string _description;
public:
    AccountType(string description): _description(description) { return; }
    ~AccountType() { return; }
    string description() const { return _description; }
};

#endif
