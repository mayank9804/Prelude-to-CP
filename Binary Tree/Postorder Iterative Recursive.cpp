/*
    Iterative, Recursive
*/
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
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

// Recursive code
void postorder(node* t){
    if(!t)
        return ;
    postorder(t->left);
    postorder(t->right);
    cout<<t->data<<' ';
}

// Iterative code
void postorderIterative(){
    stack<node*>s;
    unordered_map<node*,bool>TRCK;
    s.push(NULL);
    node* t = root;

    while(t){
        
        if(TRCK.find(t)==TRCK.end()){
            s.push(t);
            TRCK[t]=1;
        }
        if(t->left && TRCK.find(t->left)==TRCK.end()){
            t = t->left;
        }else if(t->right && TRCK.find(t->right)==TRCK.end()){
            t = t->right;
        }else{
            cout<<t->data<<' ';
            s.pop();
            t = s.top();
        }
    }

}

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        insert(new node(i));
    
    cout<<"Recursive: \n";
    postorder(root);
    cout<<'\n';

    cout<<"Iterative: \n";
    postorderIterative();
    cout<<'\n';
    return 0;
}