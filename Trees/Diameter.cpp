#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height=0;
    node(int a):data(a){
        left = right = NULL;
    }
};

node* root = NULL;

int height(node* r){
    if(!r)
        return 0;
    if(r->height!=0)
        return r->height;
    return r->height = (1+max(height(r->left),height(r->right)));
}

int diameter(node *r){
    return 1+height(r->left)+height(r->right);
}
void insert(char dir,node*t,node* nn){
    if(dir=='L')
        t->left = nn;
    if(dir=='R')
        t->right = nn;
}
bool csort(const pair<string,int>&A, const pair<string,int>&B){
    if(A.first.size()==B.first.size()){
        string x1 = A.first;
        string x2 = B.first;
        int j = 0;
        for(int i=0;i<x1.size();i++){
            if(x1[i]==x2[i])
                continue;
            return x1[i]<x2[i];
        }
    }
    return A.first.size()<B.first.size();
}
int maxim =-1;
void foo(node* r){
    if(!r)
        return ;
    maxim = max(diameter(r),maxim);
    foo(r->left);
    foo(r->right);
}
int main(){
    int v,r;
    cin>>v>>r;
    string s;
    int val;
    vector<pair<string,int>>INP;
    int x = (v-1);
    root = new node(r);
    while(x--){
        cin>>s;
        cin>>val;
        INP.push_back({s,val});
    }
    sort(INP.begin(),INP.end(),csort);
    for(int i=0;i<INP.size();i++){
        node* temp=root;
        s = INP[i].first;
        val = INP[i].second;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='L')
                temp=temp->left;
            else if(s[i]=='R')
                temp=temp->right;
        }
        insert(s[s.size()-1],temp,new node(val));
    }

    foo(root);
    cout<<maxim<<'\n';
    
    return 0;
}