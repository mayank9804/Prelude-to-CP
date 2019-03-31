#include <iostream>
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

void bfs(){
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            if(Q.front()==NULL)
                return ;
            cout<<Q.front()->data<<' ';
            Q.push(Q.front()->left);
            Q.push(Q.front()->right);
            Q.pop();
        }
        cout<<'\n';
    }
}

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        insert(new node(i));
    
    bfs();
    return 0;
}