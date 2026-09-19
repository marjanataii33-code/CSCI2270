#include "stepcounter.h"

#include <iostream>
using namespace std; 

StepCounter::StepCounter(){
    count = 0;

 cout<< "I am a stepcounter!" << endl;



}
int StepCounter::get(){
    return count;
}