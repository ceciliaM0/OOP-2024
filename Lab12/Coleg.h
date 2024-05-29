#include<string>
#include "Contact.h"
using namespace std;

class Coleg : public Contact {
private:
    string firm;
    string phoneNumber;
    string adress;
public:
    Coleg(string name, string firm,  string phoneNumber,  string adress);

    string getFirm() ;

    string getPhoneNumber() ;

    string getAdress() ;

    string getName() override;

    bool IsFriend() override;

};
