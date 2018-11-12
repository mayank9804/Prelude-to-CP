#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int main(int argc, char const *argv[]){

    int N;
    cin>>N;
    vector<int>arr(N);
    FORI(i,0,N)
        cin>>arr[i];
    
    sort(arr.begin(),arr.end());

    int totalVolume;
    FORI(i,0,N){
        // N-i+1
        int temp = N-i+1;
        arr[i] = arr[i]*pow(0.9,temp);
    }   
    FORI(i,0,N)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
