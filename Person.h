#ifndef PERSON_H //Abstract class with pure virtual function
#define PERSON_H // player inherits from this 

#include <iostream>
using namespace std;


class Person {
public:
    virtual void display() const = 0; //virtual function
};

#endif
