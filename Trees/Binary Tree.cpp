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
node *root = NULL;

void insert(node *&par, node *child, char dir){
    if(root==NULL){
        root = child;
    }else{
        if(dir=='L')
            par->left = child;
        else if(dir=='R')
            par->right = child;
    }
}
void printPreorder(node *t){
    if(!t)
        return;
    cout<<t->data<<'\n';
    printPreorder(t->left);
    printPreorder(t->right);
}

void printInorder(node *root){
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->data<<'\n';
    printInorder(root->right);
}
void printPostorder(node *root){
    if(!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<'\n';
}

void bfs(node *root){
    queue<node *>Q;
    Q.push(root);
    while(!Q.empty()){
        node *temp = Q.front();
        Q.pop();
        cout<<temp->data<<' ';
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}

node *searchNode(int val,node* t){
    if(!t)
        return NULL;
    if(t->data==val)
        return t;
    searchNode(val,t->left);
    searchNode(val,t->right);
}

bool isLeaf(node *t){
    if(!t->left && !t->right)
        return true;
    return false;
}

node *findDepeestNode(node *t){
    queue<node *>Q;
    Q.push(root);
    node *dR;

    while(!Q.empty()){
        node * temp = Q.front();
        Q.pop();
        
        bool check = false;
        if(temp->left){
            check = true;
            if(isLeaf(temp->left))
                dR = temp;
            Q.push(temp->left);
        }
        if(temp->right){
            check = true;
            if(isLeaf(temp->right))
                dR = temp;
            Q.push(temp->right);
        }

        if(!check)
            dR = temp;
    }
    return dR;
}


void deleteNode(int val){

    node *temp = searchNode(val,root);
    node *dR = findDepeestNode(root);
    if(dR==root)
        root=NULL;
    if(dR->right){
        temp->data = dR->right->data;
        dR->right = NULL;
    }
    else{
        temp->data = dR->left->data;
        dR->left = NULL;
    }
}

int height(node *root){
    if(!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

vector<int>PATH;
bool findPath(node* node,int val){
    if(node==NULL)
        return false;

    if(node->data==val){
        PATH.push_back(node->data);
        return true;
    }
    if(findPath(node->left,val) || findPath(node->right,val)){
        PATH.push_back(node->data);
        return true;
    }
    return false;
}

int main(){
//     5
//    6 7
//   8   9  
    insert(root,new node(1),'-');
    insert(root,new node(2),'L');
    insert(root,new node(3),'R');
    insert(root->left,new node(4),'L');
    insert(root->left,new node(5),'R');

    cout<<"PREORDER:\n";
    printPreorder(root);
    cout<<"INORDER: \n";
    printInorder(root);
    cout<<"POSTORDER:\n";
    printPostorder(root);

    cout<<"BFS:\n";
    bfs(root);

    // deleteNode(3);

    cout<<'\n';
    // bfs(root);

    cout<<height(root);



    findPath(root,8);
    for(int i=PATH.size()-1;i>=0;i--)
        cout<<PATH[i]<<' ';
    cout<<'\n';
    return 0;
}