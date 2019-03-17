#include <bits/stdc++.h>
using namepsace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int a):data(a){
        left=NULL;
        right=NULL;
    }
};


vector<int>PAR();

int main(){
    
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->right = new node(7);
    root->left->left = new node(4);
    
    check(2,3);
    return 0;

}