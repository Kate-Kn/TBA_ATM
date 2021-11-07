#ifndef CRYPTOR_H
#define CRYPTOR_H
#include <unistd.h>
#include "ICryptor.h"

class Cryptor: public ICryptor{
private:
    virtual string doCryptPassword(const string&) const override;
public:
    Cryptor(){ return; }
    Cryptor(const Cryptor&){ return; }
    ~Cryptor() { return; }
};

#endif // CRYPTOR_H
