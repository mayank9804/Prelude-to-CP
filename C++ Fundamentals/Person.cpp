#pragma once
#include "Person.h"

Person::Person(string a,string b,int c):firstname(a),lastname(b),age(c){}

Person::~Person(){}

string Person::getName(){
    return firstname + " " + lastname;
}