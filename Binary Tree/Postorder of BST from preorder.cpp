#include <iostream>
#include <vector>
using namespace std;


void pre2post(int arr[],int& ind,int minLimit,int maxLimit,int n){
    
    if(ind>=n)
        return ;
    
    int val = arr[ind];
    if(val>minLimit && val<maxLimit){
        ind+=1;
        pre2post(arr,ind,minLimit,val,n);
        pre2post(arr,ind,val,maxLimit,n);
        cout<<val<<' ';
    }

}

void post2pre(int arr[],int ind,int minLimit,int maxLimit,int n){
    if(ind<0)
        return ;
    
    for(int i=ind;i>=0;i--){
        if(arr[i]>minLimit && arr[i]<maxLimit){
            
            cout<<arr[i]<<' ';
            post2pre(arr,i-1,minLimit,arr[i],n);
            post2pre(arr,i-1,arr[i],maxLimit,n);
            break;
            
        }
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int p = 0;
    // pre2post(arr,p,INT32_MIN,INT32_MAX,n);

    p = n-1;
    post2pre(arr,n-1,INT32_MIN,INT32_MAX,n);
}