#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct node{
    string data;
    node* left = NULL;
    node* right = NULL;
    node(){}
    node(string x):data(x){}
};

bool isOperator(string a){
    return a=="+" || a=="-" || a=="/" || a=="*" || a=="^";
}

// node* construct(char a[],int n){
//      TO use this peice of code please make sure to change char to string in here
//     stack<node*>s;
//     for(int i=0;i<n;i++){
        
//         if(!isOperator(a[i]))
//             s.push(new node(a[i]));
//         else{
//             node* t = new node(a[i]);
//             if(!s.empty()){
//                 t->right = s.top();
//                 s.pop();
//             }
//             if(!s.empty()){
//                 t->left = s.top();
//                 s.pop();
//             }
//             s.push(t);
//         }
//     }
//     return s.top();
// }

void preorder(node* root){
    if(!root)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int evaluate(node* root){

    if(!isOperator(root->data))
        return stoi(root->data);
    
    
    switch(root->data[0]){
        case '+':
            return evaluate(root->left)+evaluate(root->right);
            break;
        case '-':
            return abs(evaluate(root->left)-evaluate(root->right));
            break;
        case '*':
            return evaluate(root->left)*evaluate(root->right);
            break;
        case '/':
            return evaluate(root->left)/evaluate(root->right);
            break;
        case '^':
            return evaluate(root->left)^evaluate(root->right);
            break;
    }
    
}

int main(){
    // char arr[] = "54*100";
    // node* root = construct(arr,(sizeof(arr)/sizeof(arr[0]))-1);

    node *root = new node("+"); 
    root->left = new node("*"); 
    root->left->left = new node("5"); 
    root->left->right = new node("4"); 
    root->right = new node("-"); 
    root->right->left = new node("100"); 
    root->right->right = new node("20"); 
    delete(root);

    root = new node("+"); 
    root->left = new node("*"); 
    root->left->left = new node("5"); 
    root->left->right = new node("4"); 
    root->right = new node("-"); 
    root->right->left = new node("100"); 
    root->right->right = new node("/"); 
    root->right->right->left = new node("20"); 
    root->right->right->right = new node("2"); 

    
    preorder(root);
    cout<<'\n';
    cout<<evaluate(root);
    return 0;
}