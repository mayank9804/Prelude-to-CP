#include <iostream>
using namespace std;


struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int a):data(a){}
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


void preorder(node* t){
    if(!t)
        return ;
    cout<<t->data<<' ';
    preorder(t->left);
    preorder(t->right);
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    constructTree(arr,0,n-1,NULL,'-');
    preorder(root);
}