#include "Cunoscut.h"

#include <utility>

string Cunoscut::getName() {
   return this->name;
}

string Cunoscut::getPhoneNumber() {
    return phoneNumber ;
}

bool Cunoscut::IsFriend() {
    return false;
}


Cunoscut::Cunoscut(string name,string phoneNumber) {
this->name=std::move(name);
this->phoneNumber=std::move(phoneNumber);
}
