#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int a):data(a){
        left = right = NULL;
    }
};
Node* root = NULL;



void insert(Node *temp){
    if(!root){
        root = temp;
    }else{
        queue<Node*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            Node* t = Q.front();
            Q.pop();
            if(!t->left){
                t->left = temp;
                break;
            }else{
                Q.push(t->left);
            }
            if(!t->right){
                t->right = temp;
                break;
            }else{
                Q.push(t->right);
            }
        }
    }
}

void inorderREC(Node* r){
    if(!r)
        return;
    inorderREC(r->left);
    cout<<r->data<<'\n';
    inorderREC(r->right);
}

void inorderWithoutREC(){

    stack<Node*>st;
    Node* curr = root;

    while(1){

        while(curr!=NULL){
            // cout<<curr->data<<'\n';
            st.push(curr);
            curr = curr->left;
        }

        if(!st.empty()){
            cout<<st.top()->data<<' ';
            curr = st.top()->right;
            st.pop();
        }else{
            return ;
        }
    }
}
int main(){
    int N,val;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>val;
        insert(new Node(val));
        // inorderREC(root);
    }
    cout<<"INSERTED\n";

    // inorderREC(root);
    inorderWithoutREC();
    return 0;
}