
#include <iostream>
#include "Prieten.h"
#include "Cunoscut.h"
#include "Agenda.h"
#include "Coleg.h"
#include<vector>

using namespace std;

int main()
{    Prieten prieten ("Miruna", "15iulie2002", "0740620101", "Iasi");
     Cunoscut cunoscut ("Mihaela", "0753124869");
     Coleg coleg("Cecilia","Bla bla firm", "1234567890", "123 Main Street");
     Agenda agenda1;
     agenda1.addContact(&prieten);
     agenda1.addContact(&coleg);
     agenda1.addContact(&cunoscut);

    agenda1.searchContactByName("Miruna");
    return 0;
}
