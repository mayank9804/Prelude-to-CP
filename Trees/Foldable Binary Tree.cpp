#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int a):data(a){}
};
node *root = NULL;
void insert(node *PAR,node *child,char dir){
    if(!PAR){
        root = child;
    }else{
        if(dir=='L')
            PAR->left = child;
        else if(dir=='R')
            PAR->right = child;
    }
}
bool foldable(node *a,node *b){
    if(!a && !b)
        return 1;
    else if(!a || !b)
        return 0;
    return foldable(a->left,b->right) && foldable(a->right,b->left);
}
bool isFoldable(node *root){
    if(!root)
        return 1;
    else
        return foldable(root->left,root->right);
}
int main(){
    insert(root,new node(10),'-');
    insert(root,new node(7),'L');
    insert(root,new node(15),'R');
    insert(root->left,new node(9),'R');
    insert(root->right,new node(11),'L');
    insert(root->left->right,new node(9),'R');

    cout<<isFoldable(root);
    return 0;
}