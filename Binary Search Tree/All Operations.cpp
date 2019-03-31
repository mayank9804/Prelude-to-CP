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

node* insert(node* t,node* toInsert){
    
    if(!root){
        root = toInsert;
        return root;
    }else{
        if(t==NULL)
            return toInsert;
        if(toInsert->data < t->data)
            t->left = insert(t->left,toInsert);
        else if(toInsert->data > t->data)
            t->right = insert(t->right,toInsert);
    }
    return t;
}

void dfs(node* t){
    if(!t)
        return ;
    cout<<t->data<<' ';
    dfs(t->left);
    dfs(t->right);
}

bool search(int key,node* t){
    if(t==NULL)
        return false;
    
    if(key<t->data)
        return search(key,t->left);
    else if(key>t->data)
        return search(key,t->right);

    return 1;
}

node* findMe(int key,node* t){
    if(!t)
        return NULL;
    if(key<t->data)
        return findMe(key,t->left);
    else if(key>t->data)
        return findMe(key,t->right);
    return t;
}

node* findMin(node* t){
    if(t->left)
        return findMin(t->left);
    return t;
}

node* deleteNode(int key,node* t){
    if(!t){
        return NULL;
    }
    if(key<t->data)
        t->left = deleteNode(key,t->left);
    else if(key>t->data)
        t->right = deleteNode(key,t->right);

    else{
        if(!t->left){
            node* temp = t->right;
            free(t);
            return temp;
        }else if(!t->right){
            node* temp = t->left;
            free(t);
            return temp;
        }


        /* Inorder Successor */
        node* inorderSuccessor = findMin(root->right);
        swap(inorderSuccessor->data,t->data);

        t->right = deleteNode(inorderSuccessor->data,t->right);
    }

    return t;
}

int main(){

    int N,val;
    cin>>N;
    /* Insertion */
    for(int i=0;i<N;i++){
        cin>>val;
        insert(root,new node(val));
    }
    /* Traversal */
    dfs(root);
    cout<<'\n';
    /* Searching */
    cout<<search(38,root)<<'\n';
    cout<<search(41,root)<<'\n';

    /*Deletion*/
    int key;
    cin>>key;
    root = deleteNode(key,root);

    dfs(root);
    return 0;
}