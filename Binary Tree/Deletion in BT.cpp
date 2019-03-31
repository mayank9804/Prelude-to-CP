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
struct deleteUtil{
    node* cur;
    node* par;
    char dir;
    deleteUtil(){};
    deleteUtil(node* a,node* b,char d){
        cur = a;
        par = b;
        dir = d;
    }
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
            if(Q.front()==NULL){
                Q.pop();
                continue ;
            }
            cout<<Q.front()->data<<' ';
            Q.push(Q.front()->left);
            Q.push(Q.front()->right);
            Q.pop();
        }
        cout<<'\n';
    }
}


node* find(int key){
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){

        if(Q.front()==NULL)
            continue ;
        if(Q.front()->data == key){
            return Q.front();
        }
        Q.push(Q.front()->left);
        Q.push(Q.front()->right);
        Q.pop();
    }
    return NULL;
}

void deleteNode(int key){
    node* deleteMe = find(key);
    if(!deleteMe)
        return;
    
    queue<deleteUtil>Q;
    deleteUtil x(root,NULL,'-');
    Q.push(x);
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        
        // check if leaf node
        if(!x.cur->left && !x.cur->right){
            if(x.cur==root && deleteMe==root){
                root = NULL;
                break;
            }
            if(x.dir=='L'){
                swap(deleteMe->data,x.cur->data);
                x.par->left = NULL;
            }
            else if(x.dir == 'R'){
                swap(deleteMe->data,x.cur->data);
                x.par->right = NULL;
            }
            break;
        }
        else{
            if(x.cur->left)
                Q.push(deleteUtil(x.cur->left,x.cur,'L'));
            if(x.cur->right)
                Q.push(deleteUtil(x.cur->right,x.cur,'R'));
        }

    }
}


int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        insert(new node(i));
    
    bfs();
    cout<<'\n';
    deleteNode(3);
    bfs();
    cout<<'\n';
    deleteNode(0);
    bfs();
    return 0;
}