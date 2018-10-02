#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string firstname;
        string lastname;
        int age;
    public:
        string getName() const;
    
    Person(string a,string b,int c);
    Person()=default;
    ~Person();
};

Person::Person(string a,string b,int c):firstname(a),lastname(b),age(c){}
Person::~Person(){
    cout<<"Destructing person: "<<firstname<<" "<<lastname<<"\n";
}
string Person::getName() const{
    // The following would generate compiler error
    // firstname="Monkey"
    return firstname + " " + lastname + "\n";  
}

int main(){
    {
        Person p("Mayank","Sharma",18);
        cout<<p.getName();
    }
    {
        Person p("Demo","User",50);
    }
    
    return 0;
}
