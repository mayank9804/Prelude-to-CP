#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    
    int N,temp;
    cin>>N;
    priority_queue<int,vector<int>, greater<int>> arr;
    for(int i=0;i<N;i++){
        cin>>temp;
        arr.push(temp);
    }
    int sum=0;
    
    while(!arr.empty()){
        int fmini,smin;
        fmini=smin=0;
        fmini = arr.top();
        arr.pop();
        if(!arr.empty()){
            smin = arr.top();
            arr.pop();
        }
        sum+=(fmini+smin);
        if(arr.size()!=0)
            arr.push(fmini+smin);
    }   
    cout<<sum;
    return 0;
}
