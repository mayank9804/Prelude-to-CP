#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(int x):data(x){}
};
node* root;
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
void preorder(node* t){
    if(!t)
        return ;
    cout<<t->data<<' ';
    preorder(t->left);
    preorder(t->right);
}

bool isSymmetric(){
    stack<node*>S;
    map<node*,bool>MAP;
    bool flag = true;
    node* p = root;
    node* q = root;
    S.push(NULL);
    S.push(NULL);
    while(p && q){
        

        if(MAP.find(p)==MAP.end() && MAP.find(q)==MAP.end()){
            
            S.push(p);
            S.push(q);
            MAP[p]=1;
            MAP[q]=1;
        }
        else if((p->left && !q->right) || (!p->left && q->right)){
            flag = 0;
            break;
        }
        else if((p->left && q->right) && (p->left->data)!=(q->right->data)){
            
            flag = 0;
            break;
        }
        
        
        else if((!p->left && !q->right) || (MAP.find(p->left)!=MAP.end() && MAP.find(q->right)!=MAP.end())){
            
            if((p->right && !q->left) || (!p->right && q->left)){
                flag = 0;
                break;
            }
            else if((p->right && q->left) && (p->right->data != q->left->data)){
                flag = 0;
                break;
            }
            else if((!p->right && !q->left)|| (MAP.find(p->right)!=MAP.end() && MAP.find(q->left)!=MAP.end()) ){
                
                S.pop();
                S.pop();
                q = S.top();
                S.pop();
                p = S.top();
                S.pop();
                
                S.push(p);
                S.push(q);

            }
            else if((p->right && q->left) && (MAP.find(p->right)==MAP.end() && MAP.find(q->left)==MAP.end())){
                
                p = p->right;
                q = q->left;
                
            }
        }
        else if((p->left && q->right) && (MAP.find(p->left)==MAP.end() && MAP.find(q->right)==MAP.end())){
            p = p->left;
            q = q->right;
        }
    }

    if(flag)
        return 1;
    return 0;

}
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    constructTree(arr,0,n-1,NULL,'-');
    preorder(root);
    cout<<'\n';
    cout<<isSymmetric();
    return 0;
}