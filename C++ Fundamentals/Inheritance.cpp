#include <iostream>
#include <string>
using namespace std;

class Mammal{
    private:
        string type;
        int age;
    public:
        string getType();
    Mammal(string a,int c);
    Mammal()=default;
    ~Mammal();
};

Mammal::Mammal(string a,int b):type(a),age(b){}
Mammal::~Mammal(){
    cout<<"Destructing Mammal: "<<type<<"\n";
}
string Mammal::getType(){
    return type;
}

class Human: public Mammal{
    private:
        string firstname;
        string lastname;
    public:
        Human(string type,int age,string fname,string lname);
        ~Human(){}
};
Human::Human(string type,int age,string fname,string lname):Mammal(type,age),firstname(fname),lastname(lname){}

int main(){
    Human h1("Human",19,"Mayank","Sharma");

    cout<<h1.getType()<<"\n";
}


// Modes of Inheritance

//     Public mode: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
//     Protected mode: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.
//     Private mode: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class.


// class A 
// {
// public:
//     int x;
// protected:
//     int y;
// private:
//     int z;
// };
 
// class B : public A
// {
    // x is public
    // y is protected
    // z is not accessible from B
// };
 
// class C : protected A
// {
    // x is protected
    // y is protected
    // z is not accessible from C
// };
 
// class D : private A    // 'private' is default for classes
// {
    // x is private
    // y is private
    // z is not accessible from D
// };

// Single Inheritance
// Multiple Inheritance
// Multilevel Inheritance
// Hierarchical Inheritance
// Hybrid (Virtual) Inheritance
