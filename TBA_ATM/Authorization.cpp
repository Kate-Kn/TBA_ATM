#include "Authorization.h"

Card Authorization::doAuthorize(const AuthCard& authCard) const{
    try{
            Card card = storage().checkAuthCard(authCard);
            return card;
    }catch (IStorage::BadStorage bd){
        throw BadAuthorization(bd.diagnose());
    }
}
