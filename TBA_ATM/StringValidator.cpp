#include "StringValidator.h"

bool isNumericalSequence(const QString& str){
    return regex_match (str.toStdString(), regex("[0-9]*") );
}
