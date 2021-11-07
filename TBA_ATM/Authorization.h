#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "IAuthorization.h"

class Authorization: public IAuthorization{
private:
    virtual Card doAuthorize(const AuthCard& ) const override;
public:
    Authorization(IStorage newStorage, ICryptor newCryptor): IAuthorization(newStorage, newCryptor) { return; }
    Authorization(const Authorization& auth): IAuthorization(auth.storage(), auth.cryptor()) { return; }
};

#endif
