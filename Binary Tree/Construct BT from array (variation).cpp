#include <iostream>
#include <string.h>
using namespace std;


struct node{
    int data;
    node* left=NULL;
    node* right=NULL;
    node(){}
    node(int x):data(x){}
};

node* root = NULL;

void preorder(node* t){
    if(!t)
        return ;
    cout<<t->data<<' ';
    preorder(t->left);
    preorder(t->right);
}

node* formnode(int arr[],node* c[],int n,int ind){
    
    if(c[ind]!=NULL){
        return c[ind];
    }
    if(arr[ind]==-1){
        root = new node(ind);
        c[ind] = root;
        return c[ind];
    }

    if(c[ind]==NULL){
        node* x = new node(ind);
        node* par = formnode(arr,c,n,arr[ind]);
        if(!par->left)
            par->left = x;
        else
            par->right = x;
        return c[ind] = x;
    }
}

void createLinkedTree(int arr[],node* c[],int n){
    
    for(int i=0;i<n;i++)
        if(c[i]==NULL)
            formnode(arr,c,n,i);
    
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* created[n];
    memset(created,NULL,sizeof(created));
    
    createLinkedTree(arr,created,n);

    preorder(root);
    
}