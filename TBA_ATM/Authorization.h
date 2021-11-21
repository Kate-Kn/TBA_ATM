#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "IAuthorization.h"

class Authorization: public IAuthorization{
private:
    virtual Card doAuthorize(const AuthCard& ) const override;
    virtual bool doCheckAuthorizationData(const AuthCard& authCard) const override;
    Authorization(const Authorization& auth) = delete;
public:
    Authorization(IStorage* newStorage, ICryptor* newCryptor): IAuthorization(newStorage, newCryptor) { return; }
};

#endif
