#ifndef LAB12_AGENDA_H
#define LAB12_AGENDA_H
#include<iostream>
#include<vector>
#include<string>
#include "Contact.h"

using namespace std;

class Agenda {
private:
    vector <Contact*> contacts;
public:
    bool searchContactByName(string name);
    vector<Contact*> GetFriends();
    void deleteContactByName(string name);
    void addContact(Contact* contact);

};


#endif
