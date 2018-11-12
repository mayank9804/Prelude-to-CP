#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    vector<int>ARR(N);
    // Taking Inputs
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    
    cout<<"Enter how many elements do you want to insert and 1-based index seperated by space\n";
    cin>>N;
    int temp1,ind;
    
    while(N--){
        cin>>temp1>>ind;
        int temp = ARR.size();
        ARR.resize(temp+1);
        for(int i=temp-1;i>=(ind-1);i--){
            ARR[i+1]=ARR[i];
        }
        ARR[ind-1]=temp1;
    }
    for(int i=0;i<ARR.size();i++){
        cout<<ARR[i]<<' ';
    }
    cout<<"\n";
    
    return 0;
}
