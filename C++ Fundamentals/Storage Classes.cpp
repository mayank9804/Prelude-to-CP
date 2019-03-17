#include <bits/stdc++.h>
using namespace std;

// extern int a;
// static int b;

// int main(){
//     // Register variables can never be declared global or static
//     cout<<a<<'\n';

//     // register int b;
//     b++;
//     cout<<b<<'\n';

//     // cout<<a<<'\n';
// }

// class ForwardReference
// {
//     int i;

//   public:
//     // call to undeclared function
//     int f();
//     int g();
// };
// int ForwardReference::f(){
//     return g()+10;
// }
// int ForwardReference::g(){
//     return i;
// }


// int main()
// {
    
//     ForwardReference fr;
//     cout << fr.f();
// }

class A{
    public:
        int x;
        A(){
            cout<<"A class constructor\n";
        }
        A(int y){
            cout<<"A param c\n";
        }
};
class B:public A{
    public:
        B(){
            cout<<"B constructor\n";
        };
        B(int y){
            A();
            cout<<"B PARAM\n";
            
        }
};
int main(){
    B a(5);
}