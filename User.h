#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User{
private:
    string _name;
    string _surname;
public:
    User(string name, string surname): _name(name), _surname(surname) { return; }
    ~User(){ return; }
    string name() const { return _name; }
    string surname() const { return _surname; }
};

#endif
