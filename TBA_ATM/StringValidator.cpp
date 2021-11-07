#include "StringValidator.h"

bool isNumericalSequence(string str){
    return regex_match (str, regex("0-9") );
}
