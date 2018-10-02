#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    
    int T,N,a,k;
    vector<int>arr;
    cin>>T;
    while(T){
        cin>>N;
        stack<int>s;
        arr = {};
        for(int i=0;i<N;i++){
            cin>>a;
            arr.push_back(a);
        }
        cin>>k;

        for(int i=0;i<arr.size() && k!=0;i++){
            if(s.size()==0)
                s.push(arr[i]);
            else if(s.top()<arr[i]){
                // delete arr[i]]]
                
                while(s.top()<arr[i]){
                    
                    arr.erase(arr.begin()+i-1);
                    k-=1;
                    i-=1;
                    if(i==0)
                        break;
                    if(k==0)
                        break;
                    s.pop();
                    if(s.size()==0)
                        break;
                }
                
                s.push(arr[i]);
            }else{
                s.push(arr[i]);
            }
        }
        
        for(int e:arr)
            cout<<e<<" ";
        cout<<"\n";
        T--;
    }
    return 0;
}
