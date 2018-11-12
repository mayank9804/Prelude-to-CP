#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *prev;
    Node *next;
    Node(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
};
void insertLast(Node *&head,Node *newNode){
    if(!head)
        head = newNode;
    else{
        Node *PTR = head;
        while(PTR->next)
            PTR = PTR->next;
        PTR->next = newNode;
        newNode->prev = PTR;
    }
}
void display(Node *head){
    if(!head){
        cout<<"Empty List\n";
        return ;
    }
    Node *PTR = head;
    while(PTR){
        cout<<PTR->val<<" ";
        PTR=PTR->next;
    }
    cout<<'\n';
}
int deleteByVal(Node *&head,int val){
    if(!head){
        cout<<"Empty List\n";
        return -1; 
    }else{
        Node *PTR = head;
        while(PTR!=NULL && PTR->val!=val)
            PTR = PTR->next;
        
        if(!PTR){
            cout<<"Cannot find element in list\n";
            return -1;
        }else{
            if(PTR==head)
                head=NULL;
            else{
                PTR->prev->next = PTR->next;
                PTR->next->prev = PTR->prev;
            }
            
            int tc = PTR->val;
            delete PTR;
            free(PTR);
            return tc;
        }
    }
}
int main(int argc, char const *argv[]){
    
    Node *h1=NULL;
    for(int i=0;i<9;i++)
        insertLast(h1,new Node(i+1));
    
    display(h1);

    deleteByVal(h1,5);
    deleteByVal(h1,6);

    display(h1);

    return 0;
}
