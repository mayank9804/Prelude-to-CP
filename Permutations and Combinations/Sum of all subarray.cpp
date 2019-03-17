#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)


int main(){

    vector<int>ARR{1,2,3,4,5,6};

    int counter = 1<<ARR.size();

    FORI(i,1,counter){
        int sum = 0;
        FORI(j,0,ARR.size()){
            if(i & (1<<j)){
                cout<<ARR[j]<<' ';
                sum+=ARR[j];
            }
        }
        cout<<'\n';
        cout<<sum<<'\n';
    }

    return 0;
}