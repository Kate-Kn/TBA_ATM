#ifndef IAUTHORIZATION_H
#define IAUTHORIZATION_H
#include "IStorage.h"
#include "ICryptor.h"
#include "AuthCard.h"
#include "Card.h"

#include <QString>

class IAuthorization{
private:
    IStorage* _storage;
    ICryptor* _cryptor;
    virtual Card doAuthorize(const AuthCard& ) const = 0;
    virtual bool doCheckAuthorizationData(const AuthCard& authCard) const = 0;
    IAuthorization(const IAuthorization&) = delete;
public:
    IAuthorization(IStorage* newStorage, ICryptor* newCryptor): _storage(newStorage), _cryptor(newCryptor) { return; }
    ~IAuthorization() { delete _storage; delete _cryptor; return; }
    class BadAuthorization;
    IStorage* storage() const { return _storage; }
    const ICryptor* cryptor() const { return _cryptor; }
    Card authorize(const AuthCard& authCard) const { return doAuthorize(authCard); }
    bool checkAuthorizationData(const AuthCard& authCard) const { return doCheckAuthorizationData(authCard); }
};

class IAuthorization::BadAuthorization{
private:
    const QString _reason;
public:
    BadAuthorization(QString reason = "") :
        _reason(reason){};
    ~BadAuthorization() {};
    QString diagnose() const { return _reason; };
};

#endif
