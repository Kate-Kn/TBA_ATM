#ifndef IAUTHORIZATION_H
#define IAUTHORIZATION_H
#include "IStorage.h"
#include "ICryptor.h"
#include "AuthCard.h"
#include "Card.h"

class IAuthorization{
private:
    IStorage _storage;
    ICryptor _cryptor;
    virtual Card doAuthorize(const AuthCard& ) const { return Card("", 0.0, User("", "")); }
public:
    IAuthorization(IStorage newStorage, ICryptor newCryptor): _storage(newStorage), _cryptor(newCryptor) { return; }
    ~IAuthorization() { return; }
    class BadAuthorization;
    IStorage storage() const { return _storage; }
    ICryptor cryptor() const { return _cryptor; }
    Card authorize(const AuthCard& authCard) const { return doAuthorize(authCard); }
};

class IAuthorization::BadAuthorization{
private:
    const string _reason;
public:
    BadAuthorization(string reason = "") :
        _reason(reason){};
    ~BadAuthorization() {};
    string diagnose() const { return _reason; };
};

#endif
