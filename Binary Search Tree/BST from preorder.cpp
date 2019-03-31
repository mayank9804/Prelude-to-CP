#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int x):data(x){}
};

node* root = NULL;

void constructBST(int arr[],int n,int& ind,int maxLimit,int minLimit,node* par){

    if(ind>=n)
        return;
    if(par==NULL){
        root = new node(arr[ind++]);
        par = root;
    }
    else if(arr[ind]>=minLimit && arr[ind]<=maxLimit){
        
        if(par->left==NULL){
            par->left = new node(arr[ind++]);
            par = par->left;
        }else{
            par->right = new node(arr[ind++]);
            par = par->right;
        }
    }

    constructBST(arr,n,ind,arr[ind],minLimit,par);
    constructBST(arr,n,ind,minLimit,arr[ind],par);
    
}

void dfs(node* t){
    if(!t)
        return;
    cout<<t->data<<' ';
    dfs(t->left);
    dfs(t->right);
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ref = 0;
    constructBST(arr,n,ref,INT32_MAX,INT32_MIN,NULL);
    dfs(root);
    cout<<'\n';
    return 0;
}