#include "Authorization.h"

Card Authorization::doAuthorize(const AuthCard& authCard) const{
    AuthCard authCopy(authCard.cardNumber(), authCard.pincode());
    authCopy.pincode(cryptor()->cryptPassword(authCard.pincode()));
    try{
        return (*storage()).getCard(authCopy.cardNumber());
    }catch (IStorage::BadStorage bd){
        throw BadAuthorization(bd.diagnose());
    }
}

bool Authorization::doCheckAuthorizationData(const AuthCard& authCard) const{
    AuthCard authCopy(authCard.cardNumber(), authCard.pincode());
    authCopy.pincode(cryptor()->cryptPassword(authCard.pincode()));
    try{
        return (*storage()).checkAuthCard(authCopy);
    }catch (IStorage::BadStorage bd){
        throw BadAuthorization(bd.diagnose());
    }
}
