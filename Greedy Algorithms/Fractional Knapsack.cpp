#include <bits/stdc++.h>
using namespace std;

struct item{
    double value;
    double weight;
};
bool customsort(item &a,item &b){
    return a.value/a.weight > b.value/b.weight;
}
int main(){
    int N,W;
    double val=0;
    cin>>N>>W;
    item arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i].value>>arr[i].weight;
    
    sort(arr,arr+N,customsort);

    int i=0;
    while(W>0){
        if(arr[i].weight<=W){
            val+=arr[i].value;
            W-=arr[i].weight;
        }else{
            val+= (arr[i].value/arr[i].weight)*W;
            W = 0;
        }
        i++;
    }
    cout<<val<<"\n";
    return 0;
}