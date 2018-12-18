
#include <bits/stdc++.h>
using namespace std;

struct activities{
    int start_time;
    int end_time;
    int id;
};

bool customsort(activities &a,activities &b){
    return a.end_time<b.end_time;
}
int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    activities arr[N];
    
    for(int i=0;i<N;i++){
        cin>>arr[i].start_time>>arr[i].end_time;
        arr[i].id = i;
    }
    sort(arr,arr+N,customsort);
    int ctr = 1;
    for(int i=0;i<N;i++){
        if(i==0){
            cout<<arr[i].id<<" "<<arr[i].start_time<<" "<<arr[i].end_time<<"\n";
        }else if(arr[i].start_time>=arr[i-1].end_time){
            cout<<arr[i].id<<" "<<arr[i].start_time<<" "<<arr[i].end_time<<"\n";
            ctr++;
        }
    }
    cout<<"Total number of jobs: "<<ctr<<"\n";

    return 0;
}
