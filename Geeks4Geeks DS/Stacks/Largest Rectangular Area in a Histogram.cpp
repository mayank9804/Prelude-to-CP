#include <bits/stdc++.h>
using namespace std;

int maximumAreaOfRectangle(vector<int> &arr){
    arr.push_back(0);
    int area = 0;
    int maxarea = area;
    stack<int>st;
    int i=0;
    while(i<arr.size()){
        if(st.empty()){
            cout<<"Initialized empty stack by "<<arr[i]<<"\n";
            st.push(i++);
        }
        else if(!st.empty()){
            if(arr[i]>=arr[st.top()]){
                cout<<"Current element "<<arr[i]<<" is greater than top of stack "<<arr[st.top()]<<". We pushed it on stack\n";
                st.push(i++);
            }
            else{
                cout<<"We encountered a smaller element "<<arr[i]<<" than the top of stack "<<arr[st.top()]<<". We pop it and check distance of it from the current element. Because this current element is the right most smallest element and between them current element forms the part of every bar.\n";
                int temp = arr[st.top()];
                st.pop();
                if(!st.empty()){
                    area = temp*(i-st.top()-1);
                }
                else
                    area = temp*i;

                cout<<"The area is "<<area<<"\n";
                cout<<"The maxarea was "<<maxarea<<"\n";
                maxarea = area>maxarea?area:maxarea;
                cout<<"The maxarea is "<<maxarea<<"\n";
            }    
        }
    }
    return maxarea;
}

int main(){
    int N;
    cin>>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    cout<<maximumAreaOfRectangle(arr);
    return 0;
}