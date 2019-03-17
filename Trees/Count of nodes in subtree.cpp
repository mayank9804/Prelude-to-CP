#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int a):data(a){
        left = right = NULL;
    }
};
node* root = NULL;

// Insert a node
void insert(node *&par,node *child,char dir){
    if(root==NULL)
        root = child;
    else{
        if(dir=='L')
            par->left = child;
        else 
            par->right = child;
    }
}
// Preoder traversal
void print(node *temp){
    if(!temp)
        return;
    cout<<temp->data<<' ';
    print(temp->left);
    print(temp->right);
}
// Get a pointer to the node where value is stored
node* searchNode(node *r,int val){
    if(!r)
        return NULL;
    if(r->data==val)
        return r;
    node* x = searchNode(r->left,val);
    if(x)
        return x;
    node* y = searchNode(r->right,val);
    if(y)
        return y;
}
// Find deepest rightmost node in the tree
node* findDeepestNode(){
    queue<node *>Q;
    
    node* dr=NULL;
    Q.push(root);
    while(!Q.empty()){
        node *T = Q.front();
        
        Q.pop();
        bool check = false;
        if(T->left){
            Q.push(T->left);
            check = 1;
        }
        if(T->right){
            Q.push(T->right);
            check = 1;
        }

        if(check)
            dr = T;
    }
    return dr;
}
// Delete a node
void deleteNode(int val){
    if(!root)
        return ;
    node* tnode = searchNode(root,val);
    node *dr = findDeepestNode();
    
    if(root->data==val && dr==NULL){
        root=NULL;
        return;
    }
    if(dr->right){
        swap(tnode->data,dr->right->data);
        dr->right=NULL;
    }else{
        swap(tnode->data,dr->left->data);
        dr->left=NULL;
    }
}
// Height of a tree
int height(node* r){
    if(!r)
        return 0;
    return 1+max(height(r->left),height(r->right));
}
// Calculate diameter of the tree
int diameter(node *r){
    if(root==r)
        return 1+height(r->left)+height(r->right);
    // Maximum length of path between two nodes
    return 1+max(height(r->left),height(r->right));
}
int main(){
//     1
//   2      3
//    4
//   5
    insert(root,new node(1),'-');
    insert(root,new node(2),'L');
    insert(root,new node(3),'R');
    insert(root->left,new node(4),'R');
    insert(root->left->right,new node(5),'L');
    print(root);
    cout<<'\n';
    // deleteNode(1);
    // print(root);
    // cout<<'\n';
    // deleteNode(2);
    // print(root);
    // cout<<'\n';
    // deleteNode(3);
    // print(root);
    // cout<<'\n';
    // deleteNode(4);
    // print(root);
    // cout<<'\n';
    // deleteNode(5);
    // print(root);
    // cout<<'\n';
    // print(root);
    
    cout<<height(root)<<'\n';;
    cout<<diameter(root);

    return 0;
}