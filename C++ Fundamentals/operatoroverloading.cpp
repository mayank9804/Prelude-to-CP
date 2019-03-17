// Operator Overloading
// Write a function that define the operator
// Usually a member function
// Ocassionaly a free function

// MyObject < Something | Something < MyObject
// bool MyClass::operator < (OtherType Something) | bool operator < (OtherType Something,MyClass obj)
// (member function),(free function,use class public function,or can be declared as friend)

#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
        string name;
        double salary;
        friend bool operator<=(double,Employee const& );
    public:
        double getSalary() const;
        Employee(string,double);
        bool operator<=(Employee) const;
};

Employee::Employee(string name,double salary):name(name),salary(salary){};
double Employee::getSalary() const{
    return salary;
}
bool Employee::operator<=(Employee obj) const{
    return salary<=obj.salary;
}// Write a function that define the operator


// Using available public functions
bool operator<=(double d,Employee const& obj){
    if(d<=obj.salary){
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    Employee e1("Mayank",1200);
    Employee e2("Souvick",1900);

    if(e1<=e2){
        cout<<"True\n";
    }
    cout<<e1.getSalary();
    cout<<e2.getSalary();
    cout<<"\n";
    cout<<(20<=e2.getSalary());
    return 0;
}
