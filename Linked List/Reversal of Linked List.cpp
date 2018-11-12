#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void insert(Node *&head, Node *newNode){
    if(!head)
        head = newNode;
    else{
        Node *PTR = head;
        while(PTR->next)
            PTR=PTR->next;
        PTR->next = newNode;
    }
}

void reverse(Node *&head){
    Node *adv=head,*prev=NULL,*temp=NULL;
    if(!adv)
        return;
    
    while(adv){
        temp = adv;
        adv = adv->next;
        temp->next = prev;
        prev = temp;    
    }
    if(!adv){
        head = prev;
    }
}
void display(Node *head){
    if(!head)
        return ;
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
int main(int argc, char const *argv[]){
    
    Node *head=NULL;
    for(int i=0;i<10;i++)
        insert(head,new Node(i+1));
    display(head);
    cout<<"\n";
    reverse(head);
    display(head);
    return 0;
}
