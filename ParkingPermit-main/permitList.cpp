#include "permitList.h"
#include "parkingPermit.h"
#include <iostream>
using namespace std;

PermitList::PermitList()
{
}

PermitList::~PermitList()
{
    cleanUpList();
}

void PermitList::addNew(int permitNumber, string studentName, char zone, int daysHeld)
{
    permits.push_back(new ParkingPermit(permitNumber, studentName, zone, daysHeld));
};

int PermitList::getCount()
{
    return static_cast<int>(permits.size());
}

// This function prints a single permit given a pointer to the permit
//TO DO STEP 1 Print: Change the parameter of this function to receive a pointer
void PermitList::PrintPermit(ParkingPermit* permit)
{
    // TO DO STEP 1 Print: Write a cout statement that prints the information in a permit
    cout << "permit says: " << endl;
    cout << permit->getStudentName() << endl;
    cout << permit->getPermitNumber() << endl;
    cout << permit->getDaysHeld() << endl;
}

// This function iterates through all of the permits and calls the PrintPermit function for each of them
void PermitList::PrintAll()
{
    // TO DO STEP 1 Print: write the call to the PrintPermit function
    for (int i = 0; i < getCount(); i++) {
        PrintPermit(permits[i]);
    }
}

// This function returns a pointer to the longestHeld permit
//TO DO STEP 2 REWARDS: Change the parameter of this function to receive a pointer
// name the parameter longestHeld
bool PermitList::getLongestHeldPermit(ParkingPermit*& longestHeld)
{
    //TO DO STEP 2 REWARDS: uncomment these lines once you have defined the parameter longestHeld

    if (getCount() == 0) {
        longestHeld = nullptr;
        return false;
    }

    longestHeld = permits[0];

    //TO DO STEP 2 REWARDS: iterate through the permits to find the longest held permit

    for (int i = 1; i < getCount(); i++) {
        if (permits[i]->getDaysHeld() > longestHeld->getDaysHeld()) {
            longestHeld = permits[i];
        }
    }

    return true;
}

// This function should return the name of the permit holder who held it longest
string PermitList::runRewards()
{
    ParkingPermit* longestHeld = nullptr;
    string result = string();

    //TO DO STEP 2 REWARDS add the parameter in the following statement
    bool found = getLongestHeldPermit(longestHeld);

    //TO DO STEP 2 REWARDS process the results of the getLongestHeldPermit call

    if (found) {
        result = longestHeld->getStudentName();
    }

    return result;
}

void PermitList::cleanUpList()
{
    for (int i = 0; i < getCount(); i++) {
        delete permits[i];
    }
}