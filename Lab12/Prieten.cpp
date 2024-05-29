#include "Prieten.h"

using namespace std;
string Prieten::getBirthday() {
    return birthday;
}

 string Prieten::getPhoneNumber()  {
    return phoneNumber;
}

 string Prieten::getAdress()  {
    return adress;
}

string Prieten::getName() {
  this->name;
}

bool Prieten::IsFriend() {
    return true;
}


Prieten::Prieten(string name, string birthday, string phoneNumber, string adress) {
 this->name=name;
 this->birthday=birthday;
 this->phoneNumber=phoneNumber;
 this->adress=adress;
}
