#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};
void push(Node *&head,Node *newNode){
    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
void pop(Node *&head){
    if(head)
        head = head->next;
}
int top(Node *head){
    return head->val;
}
int main(int argc, char const *argv[])
{
    /* code */
    Node *head=NULL;
    for(int i=0;i<9;i++)
        push(head,new Node(i+1));
    for(int i=1;i<=2;i++){
        cout<<top(head)<<"\n";
        pop(head);
    }

    return 0;
}
