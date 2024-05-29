#ifndef LAB12_PRIETEN_H
#define LAB12_PRIETEN_H
#include<string>
#include "Contact.h"

using namespace std;

class Prieten : public Contact {
private:

    string birthday;
    string phoneNumber;
    string adress;
public:
    Prieten(string name, string birthday,  string phoneNumber,  string adress);

    string getBirthday() ;

    string getPhoneNumber();

    string getAdress() ;

    string getName() override;

    bool IsFriend() override;



};


#endif
