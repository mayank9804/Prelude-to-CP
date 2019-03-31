#include <iostream>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int x):data(x){}
};

bool isFoldableUtil(node* p,node* q){

    if(!p && !q)
        return 1;

    if((!p && q) || (!q && p))
        return 0;
    
    return isFoldableUtil(p->left,q->right) && isFoldableUtil(p->right,q->left);
}

bool isFoldable(node* root){

    if(!root)
        return true;
    else
        return isFoldableUtil(root->left,root->right);
}

int main(){
    
    

    node* root = new node(1);  
    root->left = new node(4);  
    root->right = new node(1);  
    root->left->left = new node(0);  
    root->right->left = new node(6);  

    
    cout<<isFoldable(root);
    return 0;
}


