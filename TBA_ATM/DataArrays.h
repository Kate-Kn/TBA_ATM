#ifndef DATAARRAYS_H
#define DATAARRAYS_H
#include "Card.h"
#include "Account.h"
#include "Company.h"
#include "User.h"
#include <QList>
#endif // DATAARRAYS_H
class DataArrays
{
public:
    static QList<Card> cards ;
    static QList<User> users ;
    static QList<Company> companies;
    inline void generateCards()
    {
        users = QList<User>();
        cards = QList<Card>();
        for(int i=10;i<99;++i){
          Card card = Card("12" + to_string(i), i , User("petrenko" + to_string(i), "petrov" + to_string(i)));
          cards.append(card);
          users.append(User("petrenko" + to_string(i), "petrov" + to_string(i));
        }
    }
    inline void generateCompanies()
    {
        companies = QList<Company>();
        for(int i= 0;i<7;++i)
        {
            Company company = Company("give a hand", "charity");
            companies.append(company);
        }
    }

};
