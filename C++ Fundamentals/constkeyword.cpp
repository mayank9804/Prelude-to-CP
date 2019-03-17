#include <bits/stdc++.h>
using namespace std;
int kk;
class Animal{
    private:
        string name;
    public:
        string getName() const{
            // CONSTANT MEMBER FUNCTION It cannot change any member variable
            // name = "Changed";
            return name;
        }
};
void foo(int const c){
    // Const argument in function as argument
    // c+=1;
    cout<<c;
}
int main(int argc, char const *argv[])
{
    // cout<<kk<<'\n';
    // Creating a local variable const
    int const a = 5;
    //a+=1; //Will give an error
    cout<<a<<endl;

    foo(a);

    Animal P;
    P.getName();

    // int* const cpi = &a; Here pointer cpi can not be changed to point anything else cpi = &b will give error;
    // int const *cpi = &a; The value pointed by pointer cannot be changed *cpi=8 will give error
    const int* const cpi = &a;
    // *cpi = 5;
    // int b = 5;
    // cpi = &b;

    return 0;
}
