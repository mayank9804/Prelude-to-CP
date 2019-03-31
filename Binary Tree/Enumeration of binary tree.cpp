/*

A binary tree is labeled if all nodes of trees are assigned 
some values.

A binary tree is unlabeled if no nodes are labeled

*/


#include <iostream>
#include <string.h>
using namespace std;


int calculate(int n,int MEMO[]){
    
    if(n<=1)
        return 1;
    else if(n==2)
        return 2;
    if(MEMO[n]!=-1)
        return MEMO[n];
    int ans = 0;
    for(int i=0;i<n;i++)
        ans+=calculate(i,MEMO)*calculate(n-i-1,MEMO);
    
    return MEMO[n] = ans;
}

int main(){
    int n;
    cin>>n;
    int MEMO[n+1];
    memset(MEMO,-1,sizeof(MEMO));
    cout<<calculate(n,MEMO);

    // Unlabeled trees == nth catalan number (2n)!/((n+1)!*(n)!)
    // Labeled trees == nth catalan number * n! (Every unlabeled tree can be arranged in n! ways)
}