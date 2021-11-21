#include "Currency.h"

Currency::Currency(QString newName, double newRateUAH): _name(newName), _rateUAH(newRateUAH){
    if (rateUAH()<=0.0)
        throw BadCurrency("rate must be more than 0");
    return;
}
Currency::Currency(const Currency& currency): _name(currency.name()), _rateUAH(currency.rateUAH()){
    return;
}

void Currency::name(const QString& newName) {
    _name = newName;
    return;
}

void Currency::rateUAH(const double& newRate) {
    if (newRate<=0.0)
        throw BadCurrency("rate must be more than 0");
    _rateUAH = newRate;
    return;
}
