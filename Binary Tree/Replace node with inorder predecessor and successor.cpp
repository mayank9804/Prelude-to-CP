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

void constructBinaryTree(int arr[],int n,int ind,node* par,char dir){

    if(ind>=n)
        return;
    
    if(!root){
        root = new node(arr[ind]);
        par = root;
    }else{
        if(dir=='L'){
            par->left = new node(arr[ind]);
            par = par->left;
        }else if(dir=='R'){
            par->right = new node(arr[ind]);
            par = par->right;
        }
    }

    constructBinaryTree(arr,n,2*ind+1,par,'L');
    constructBinaryTree(arr,n,2*ind+2,par,'R');
    
}

void inorderTraversal(node* root,int &ind,int in[]){
    if(!root)
        return ;
    
    
    inorderTraversal(root->left,ind,in);
    in[ind++]=root->data;
    inorderTraversal(root->right,ind,in);
    
}

void replaceTree(node* root,int r[],int n,int& ind){
    if(!root)
        return;
    
    replaceTree(root->left,r,n,ind);
    root->data = r[ind++];
    cout<<root->data<<' ';
    replaceTree(root->right,r,n,ind);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    constructBinaryTree(arr,n,0,NULL,'-');
    int inorder[n];
    int ind = 0;
    inorderTraversal(root,ind,inorder);

    int replaced[n];
    
    for(int i=0;i<n;i++){
        if(i==0 && i+1<n)
            replaced[i]=inorder[i+1];
        else if(i==n-1 && i-1>=0)
            replaced[i]=inorder[i-1];
        else
            replaced[i]=inorder[i-1]+inorder[i+1];
    }
    cout<<'\n';
    ind = 0;
    replaceTree(root,replaced,n,ind);
    cout<<'\n';
    return 0;
}