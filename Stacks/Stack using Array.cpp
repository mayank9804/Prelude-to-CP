#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    
    int N;
    cout<<"Enter the fixed size of stack\n";
    cin>>N;
    int ARR[N];
    int top=0;
    while(1){
        cout<<"1. PUSH\n2. POP\n3. TOP\n4.Exit\n";
        int ch,elem;
        cin>>ch;
        switch(ch){
            case 1:
                if(top==N-1){
                    cout<<"Maximum limit reached\n";
                }else{
                    cin>>elem;
                    ARR[top++]=elem;
                }
                break;
            case 2:
                if(top<=0){
                    cout<<"No element present in stack\n";
                }else{
                    cout<<"Element "<<ARR[top-1]<<"\n";
                    top--;
                }
                break;
            case 3:
                if(top<=0){
                    cout<<"No element present in stack\n";
                }else{
                    cout<<"Element "<<ARR[top-1]<<"\n";
                }
                break;
            case 4:
                    return 0;
                break;
            default:
                cout<<"Try again\n";
                break;
        }
    }
    return 0;
}
