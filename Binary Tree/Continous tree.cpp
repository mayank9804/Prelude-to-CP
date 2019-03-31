#include <iostream>
#include <string.h>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int x):data(x){}
};
node* root = NULL;

void constructTree(int arr[],int ind,int limit,node* par,char dir){
    if(ind>limit)
        return ;
    if(!root){
        root = new node(arr[ind]);
        par = root;
    }else{
        if(dir=='L'){
            par->left = new node(arr[ind]);
            par = par->left;
        }
        else if(dir=='R'){
            par->right = new node(arr[ind]);
            par = par->right;
        }
    }
    constructTree(arr,2*ind+1,limit,par,'L');
    constructTree(arr,2*ind+2,limit,par,'R');
}

node* formnode(int arr[],node* c[],int n,int ind){
    
    if(c[ind]!=NULL){
        return c[ind];
    }
    if(arr[ind]==-1){
        root = new node(ind);
        c[ind] = root;
        return c[ind];
    }

    if(c[ind]==NULL){
        node* x = new node(ind);
        node* par = formnode(arr,c,n,arr[ind]);
        if(!par->left)
            par->left = x;
        else
            par->right = x;
        return c[ind] = x;
    }
}

void createLinkedTree(int arr[],node* c[],int n){
    
    for(int i=0;i<n;i++)
        if(c[i]==NULL)
            formnode(arr,c,n,i);
    
}

bool isContinuous(node* t){
    if(!t)
        return 1;
    
    if(t->left && abs(t->data - t->left->data)!=1)
        return 0;
    if(t->right && abs(t->data-t->right->data)!=1)
        return 0;
    
    return isContinuous(t->left) && isContinuous(t->right);
}

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    // constructTree(arr,0,N-1,NULL,'-');
    node* created[N];
    memset(created,NULL,sizeof(created));
    
    createLinkedTree(arr,created,N);

    cout<<isContinuous(root);
}