#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define For(i,a,b) for(int i=a;i<b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define ci pair<char,int>
#define pb push_back
typedef unsigned long long ull;


struct Node{
    int data;
    vector<Node*>children;
    Node(){

    }
    Node(int x):data(x){

    }
};
Node* findNode(Node* root,int data){
    if(!root)
        return NULL;
    else{
        if(root->data == data){
            return root;
        }else{
            For(i,0,root->children.size()){
                // cout<<root->children[i]->data<<"\n";
                Node* temp=findNode(root->children[i],data);
                if(!temp)
                    continue;
                else
                    return temp;
            }
        }
    }
}
void insertNode(Node** root,int PAR,int CHI){
    Node* rootPar = new Node(PAR);
    Node* child = new Node(CHI);

    if(!*root){
        *root = rootPar;
        (*root)->children.pb(child);
    }else{
        Node* temp = findNode(*root,PAR);
        temp->children.pb(child);
    }
}
void fillQueue(Node* r1,queue<int>&s){
    queue<Node*>q;
    if(!r1)
        return;
    q.push(r1);
    while(!q.empty()){
        Node* c = q.front();
        q.pop();
        s.push(c->data);
        For(i,0,c->children.size()){
            q.push(c->children[i]);
        }
    }
}
bool checkForMirror(Node* r2,queue<int>&st){
    queue<Node*>q;
    if(!r2)
        return false;
    q.push(r2);
    while(!q.empty()){
        Node* c = q.front();
        q.pop();
        if(c->data != st.front()){
            return false;
        }else{
            st.pop();
        }
        Ford(i,c->children.size()-1,0){
            q.push(c->children[i]);
        }
    }
    return true;
}
int main(int argc, char const *argv[]){
    
    // FAST;
    TEST;
    Node *tree1,*tree2;
    
    int a,b,PAR,CHILD,c;
    while(T--){
        queue<int>qt;
        tree1 = tree2 = NULL;
        cin>>a>>b;
        c=2*b;
        while(c){
            cin>>PAR>>CHILD;
            insertNode(&tree1,PAR,CHILD);
            c-=2;
        }
        c=2*b;
        while(c){
            cin>>PAR>>CHILD;
            insertNode(&tree2,PAR,CHILD);
            c-=2;
        }
        // cout<<"Filling\n";
        fillQueue(tree1,qt);
        
        cout<<checkForMirror(tree2,qt)<<"\n";
    }
    return 0;
}
