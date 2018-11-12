// P smooth number 
// LPF OF A NUMBER SHUD BE LESS THAN BE EQUAL TO LESS THAN P
// That's a P smooth number
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int num){
    if(num==1)
        return false;
    if(num==2 || num==3)
        return true;
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int lpf(int num){
    for(int i=num;i>1;i--){
        if(num%i==0 && isPrime(i)){
            return i;
        }
    }

}
void fill7smoothNumbers(unordered_map<int,bool>&trcK){
    for(int i=2;i<=200;i++)
        if(lpf(i)<=7)
            trcK[i] = true;
}

int main(int argc, char const *argv[]){
    
    unordered_map<int,bool>trcK;
    fill7smoothNumbers(trcK);
    int Q,L,R;
    cin>>Q;
    while(Q--){
        cin>>L>>R;
        for(int i=L;i<=R;i++)
            if(trcK[i])
                cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
