#ifndef CRYPTOR_H
#define CRYPTOR_H
<<<<<<< HEAD
#include <QString>
=======
>>>>>>> parent of 37bd244... sqlrunner class
#include <unistd.h>
#include "ICryptor.h"

class Cryptor: public ICryptor{
private:
    virtual QString doCryptPassword(const QString&) const override;
public:
    Cryptor(){ return; }
    Cryptor(const Cryptor&){ return; }
    ~Cryptor() { return; }
};

#endif // CRYPTOR_H
