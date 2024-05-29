#include "Coleg.h"

#include <string>

using namespace std;
string Coleg::getFirm() {
    return firm;
}

string Coleg::getPhoneNumber() {
    return phoneNumber;
}

string Coleg::getAdress() {
    return adress;
}

string Coleg::getName() {

    return this->name;
}

bool Coleg::IsFriend() {
    return false;
}

Coleg::Coleg( string name,string firm, string phoneNumber, string adress) {
    this->name=name;
    this->firm=firm;
    this->phoneNumber=phoneNumber;
    this->adress=adress;
}
