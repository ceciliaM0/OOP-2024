#ifndef LAB12_CUNOSCUT_H
#define LAB12_CUNOSCUT_H


#include "Contact.h"

class Cunoscut : public Contact{
    private:
    string phoneNumber;

public:
    explicit Cunoscut(string name,string phoneNumber);

    string getPhoneNumber();

    string getName() override;

    bool IsFriend() override;


};


#endif
