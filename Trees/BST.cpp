#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left=NULL;
    Node *right=NULL;
    Node(int a):data(a){}
};

Node* root=NULL;
Node* insert(Node* t,int val){
    if(!root){
        root = new Node(val);
        return root;
    }
    if(!t)
        return new Node(val);
    if(val<=t->data)
        t->left = insert(t->left,val);
    else
        t->right = insert(t->right,val);
    return t;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
Node* find(int val,Node* t){
    if(val==t->data){
        // root;
        return NULL;
    }
    if(val>t->data){
        if(t->right && val==t->right->data)
            return t;
        return find(val,t->right);
    }else if(val<t->data){
        if(t->left && val==t->left->data)
            return t;
        return find(val,t->left);
    }

}

Node* findMin(Node *t){
    if(!t->left)
        return t;
    return findMin(t->left);
}

void deleteNode(int val){
    // cout<<val<<' ';
    Node* x = find(val,root);
    // You have the parent of node to be deleted
    // cout<<x->data<<'\n';
    Node* p;
    char dir;
    if(!x){
        p = root;
    }
    else if(x->left && x->left->data==val){
        p = x->left;
        dir='L';
    }else if(x->right && x->right->data==val){
        p = x->right;
        dir='R';
    }
    
    // to delete is p and its parent is x

    if(!p->left && !p->right){
        // its a leaf node
        if(dir=='L')
            x->left=NULL;
        else if(dir=='R')
            x->right=NULL;
        else
            root = NULL;
    }else if(p->left && !p->right){
        int xx = p->left->data;
        deleteNode(p->left->data);
        p->data = xx;
        // coming back to it
        
    }else if(p->right && !p->left){
        int xx = p->right->data;
        deleteNode(p->right->data);
        p->data = xx;
        // Coming back to it
        
    }else if(p->left && p->right){
        Node* nodemin = findMin(p->right);
        int xx = nodemin->data;
        deleteNode(nodemin->data);
        p->data = xx;
    }

}

int main(){

    int N,val;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>val;
        insert(root,val);
    }
    inorder(root);
    cout<<'\n';
    deleteNode(7);
    inorder(root);
    cout<<'\n';
    deleteNode(5);
    inorder(root);
    return 0;
}