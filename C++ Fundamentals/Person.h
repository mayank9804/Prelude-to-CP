#pragma once
#include <string>
using std::string;
class Person{
    private:
        string firstname;
        string lastname;
        int age;
    public:
        string getName();
    
    Person(string a,string b,int c);
    Person()=default;
    ~Person();
};


class Person{
    private:
        string firstname;
        string lastname;
        int age;
    public:
        string getName();
    
    Person(string a,string b,int c);
    Person()=default;
    ~Person();
};

// Struct and class are same in all means
// Both have member functions, plain old data,constructor,destructor
// Only difference being default access in struct is public
// where as in class it's private