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

void constructTree(int arr[],int ind,int limit,node* par,char dir){
    if(ind>limit)
        return ;
    if(!root){
        root = new node(arr[ind]);
        par = root;
    }else{
        if(dir=='L'){
            par->left = new node(arr[ind]);
            par = par->left;
        }
        else if(dir=='R'){
            par->right = new node(arr[ind]);
            par = par->right;
        }
    }
    constructTree(arr,2*ind+1,limit,par,'L');
    constructTree(arr,2*ind+2,limit,par,'R');
}

void inorder(node* t,int arr[],int& ind,bool flag){
    if(!t)
        return ;
    inorder(t->left,arr,ind,flag);
    if(flag)
        arr[ind++] = t->data;
    else
        t->data = arr[ind++];
    
    inorder(t->right,arr,ind,flag);
}


void dfs(node* t){
    if(!t)
        return ;
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
    
    constructTree(arr,0,n-1,NULL,'-');
    dfs(root);
    cout<<'\n';

    int ind = 0;
    inorder(root,arr,ind,1);
    
    sort(arr,arr+n);
    
    ind = 0;
    inorder(root,arr,ind,0);
    
    dfs(root);
    cout<<'\n';

    return 0;
}