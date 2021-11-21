#ifndef ICRYPTOR_H
#define ICRYPTOR_H
#include <string>
using namespace std;

class ICryptor{
private:
    virtual string doCryptPassword(const string&) const {return "";};
public:
    class BadCryptor;
    ICryptor(){ return; };
    virtual ~ICryptor(){ return; };
    string cryptPassword(const string& str){ return doCryptPassword(str); }
};

class ICryptor::BadCryptor{
private:
    const string _reason;
public:
    BadCryptor(string reason = "") :
        _reason(reason){};
    ~BadCryptor() {};
    string diagnose() const { return _reason; };
};

#endif // ICRYPTOR_H
