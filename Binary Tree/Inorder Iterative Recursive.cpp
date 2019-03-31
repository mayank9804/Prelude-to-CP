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
void inorder(node* t){
    if(!t)
        return ;
    inorder(t->left);
    cout<<t->data<<' ';
    inorder(t->right);  
}

// Iterative code
void inorderIterative(){
    stack<node*>s;
    unordered_map<node*,bool>TRCK;
    node* t = root;
    s.push(NULL);

    while(t){

        if(TRCK.find(t)==TRCK.end()){
            s.push(t);
            TRCK[t]=1;
        }
        if(t->left && TRCK.find(t->left)==TRCK.end()){
            t = t->left;
        }else if(!t->left || TRCK.find(t->left)!=TRCK.end()){
            cout<<t->data<<' ';
            s.pop();
            if(t->right && TRCK.find(t->right)==TRCK.end()){
                t = t->right;
            }else{
                t = s.top();
            }
        }
        
        

    }

}

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        insert(new node(i));
    
    cout<<"Recursive: \n";
    inorder(root);
    cout<<'\n';

    cout<<"Iterative: \n";
    inorderIterative();
    cout<<'\n';
    return 0;
}