#include <bits/stdc++.h>
using namespace std;

vector<int>PRE{1,2,4,3,5,6};
vector<int>IN{4,2,1,5,3,6};

int ind = 0;
void process(int l,int r,int ind,int prev){
    
    if(l>r)
        return;
    
    int pos = find(IN.begin(),IN.end(),PRE[ind])-IN.begin();
    process(l,pos-1,ind+1,ind);
    process(pos+1,r,ind+(pos-l)+1,ind);
    cout<<PRE[ind]<<' ';
}
int main(){

    process(0,PRE.size()-1,0,-1);
    return 0;
}