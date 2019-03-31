/*
    Iterative, Recursive
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int x):data(x){}
};

node* root = NULL;

void insert(node* t){

    if(!root){
        root = t;
        return;
    }

    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node* f = Q.front();
        Q.pop();

        if(f->left==NULL){
            f->left = t;
            break;
        }else if(f->right==NULL){
            f->right = t;
            break;
        }

        Q.push(f->left);
        Q.push(f->right);
    }

}

// Recursive
void preorder(node* t){
    if(!t)
        return ;
    cout<<t->data<<' ';
    preorder(t->left);
    preorder(t->right);
}

// Iterative
void preorderIterative(){
    stack<node*>s;
    node* t = root;
    s.push(NULL);

    while(t){
        cout<<t->data<<' ';
        if(t->right)
            s.push(t->right);
        if(t->left){
            t = t->left;
        }else{
            t = s.top();
            s.pop();
        }
    }

}


int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        insert(new node(i));
    
    cout<<"Recursive: \n";
    preorder(root);
    cout<<'\n';

    cout<<"Iterative: \n";
    preorderIterative();
    cout<<'\n';
    return 0;
}