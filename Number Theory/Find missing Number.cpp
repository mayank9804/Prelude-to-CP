#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)

int main(){
    int N;
    cin>>N;
    int xor1;

    // Optimised method to calculate xor from 1 to n
    switch(N%4){
        case 0:
            xor1 = N;
            break;
        case 1:
            xor1 = 1;
            break;
        case 2:
            xor1 = N+1;
            break;
        case 3:
            xor1 = 0;
            break;
    }
    int temp;
    FORI(i,0,N-1){
        cin>>temp;
        xor1 = xor1^temp;
    }
    cout<<"Missing number is "<<xor1<<'\n';
    return 0;
}
