#include <bits/stdc++.h>
using namespace std;


// Base class reference can actually 
// refer to a derived class instance

// Any base class function can be called 
// through a base refernce to a derived instance
// Which function would run?
// It depends
// If the function is marked virtual -- derived class function gets executed
//(POLYMORPHISM)
// If its not base class would run

// Can't call derived class fucntions
// Compiler only knows this is a base class refernece

// Can't create a derived class reference that refers to base class instance

// IF YOU HAVE DERIVED INSTANCE YOU CAN ONLY REFER TO IT USING BASE CLASS REFERENCE

// A pointer to a base class can actually point to a derived class instance
// Any base class function can then be called through the pointer 
// Virtual function--derived class function gets executed
// else base classs
// OPPOSITE IS NOT TRUE


class Person{
    private:
        string name;
        int age;

    public:
        Person(string name,int age):name(name),age(age){}
        virtual ~Person(){
            cout<<"Person deleted\n";
        }
        virtual string getName() const {return name;}
};

class Tweeter : public Person{
    private:
        string tweeterHandle;
    public:
        Tweeter(string name,int age,string th):Person(name,age),tweeterHandle(th){}
        ~Tweeter(){cout<<"Tweeter instance deleted\n";}
        // Overriding
        string getName() const{
            return Person::getName()+" "+tweeterHandle;
        }
};
int main(int argc, char const *argv[])
{
    Person p1("Mayank",19);
    Person &rp1 = p1;
    Person *pp1 = &p1;

    Tweeter t1("Mayank",19,"mayank9804");
    Person &prt1 = t1;
    Person *ppt1 = &t1;
    Tweeter &rt1 = t1;
    Tweeter *pt1 = &t1;

    cout<<rp1.getName()<<endl;
    cout<<pp1->getName()<<endl;
    cout<<prt1.getName()<<endl;
    cout<<ppt1->getName()<<endl;
    cout<<rt1.getName()<<endl;
    cout<<pt1->getName()<<endl;

    
    return 0;
}

// When a function is marked virtual what matters
// is what the pointer or reference is pointing 
// to 
// If not you get what the code is thinking it to be


// DO note while inheritance
// if you are copying base class = dderived class
// Extra member would get thrown away
// COuld be the case when you pass object to function as arguments
// Alwasys better to do it reference based

// Indirection opens the door to polymorphism
// and if your design is built on polymorphism
// passing things around by value just brings
// slicing into play and throws away your polymorphism
// so thats why you see so much indirection when there's 
// inheritance hierarchies

// You can also typecast to have the base class pointer as derived class pointer if its actually points to
// derived class
// static_cast<type>
// dynmaic_cast<type>