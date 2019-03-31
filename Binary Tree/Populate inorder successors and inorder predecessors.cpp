#include <iostream>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node* next = NULL;
    node(){}
    node(int x):data(x){}
};

node* root = NULL;

void constructBinaryTree(int arr[],int n,int ind,node* par,char dir){

    if(ind>=n)
        return;

    if(!root){
        root = new node(arr[ind]);
        par = root;
    }else{
        if(dir=='L'){
            par->left = new node(arr[ind]);
            par = par->left;
        }else if(dir=='R'){
            par->right = new node(arr[ind]);
            par = par->right;
        }
    }

    constructBinaryTree(arr,n,2*ind+1,par,'L');
    constructBinaryTree(arr,n,2*ind+2,par,'R');
}

void dfs(node* t){
    if(!t)
        return ;
    cout<<t->data;
    if(t->next)
        cout<<' '<<t->next->data<<'\n';
    else
        cout<<'\n';
    dfs(t->left);
    dfs(t->right);
}

void populateInorderSuccessors(node* cur,node*& lastNode){

    if(!cur)
        return;
    populateInorderSuccessors(cur->right,lastNode);
    
    if(lastNode)
        cur->next = lastNode;
    lastNode = cur;
    populateInorderSuccessors(cur->left,lastNode);

}
void populateInorderPredecessors(node* cur,node*& lastNode){

    if(!cur)
        return;
    populateInorderPredecessors(cur->left,lastNode);
    
    if(lastNode)
        cur->next = lastNode;
    lastNode = cur;
    populateInorderPredecessors(cur->right,lastNode);

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    constructBinaryTree(arr,n,0,NULL,'-');
    node* lastNode = NULL;
    // populateInorderSuccessors(root,lastNode);
    populateInorderPredecessors(root,lastNode);
    dfs(root);
    return 0;
}