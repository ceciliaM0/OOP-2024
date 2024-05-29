#ifndef LAB12_CONTACT_H
#define LAB12_CONTACT_H
#include<string>

using namespace std;

class Contact {
protected:
    string name;
public:
    virtual string getName()=0;
    virtual bool IsFriend()=0;

};


#endif
