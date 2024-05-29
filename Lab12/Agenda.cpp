#include "Agenda.h"

bool Agenda::searchContactByName(string name) {
    for(auto contact: contacts)
        if(contact->getName()==name)
            return true;
    return false;
}

vector<Contact *> Agenda::GetFriends() {
    vector<Contact*> friends;
    for(auto contact: contacts)
      if(contact->IsFriend())
          friends.push_back(contact);
    return friends;
}

void Agenda::deleteContactByName(string name) {
  for(auto it=contacts.begin();it!=contacts.end();it++)
      if((*it)->getName()==name)
      {
          contacts.erase(it);
      }
}
void Agenda::addContact(Contact* contact) {
  contacts.push_back(contact);

}
