#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char a = 128;
    cout<<(int)a<<endl;
    for(int i=0;i<10;i++){
        a+=i;
        cout<<i<<" : "<<(int)a<<endl;
    }
    return 0;
}
