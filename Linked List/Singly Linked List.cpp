#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

void insert(Node *&head,Node *newtemp){
    if(!head){
        head = newtemp;
    }else{
        Node* PTR = head;
        while(PTR->next){
            PTR = PTR->next;
        }
        PTR->next = newtemp;
    }
}

void display(Node *head){
    if(!head){
        cout<<"List is empty\n";
        return;
    }
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}

void findMiddle(Node *head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow)
        cout<<slow->val<<"\n";
    else
        cout<<"List is empty\n";
}

int deletionByVal(Node *head,int value){
    Node *PTR = head;
    Node *PREV = NULL;
    while(PTR!=NULL && (PTR->val != value)){
        PREV=PTR;
        PTR = PTR->next;
    }
    if(!PTR){
        cout<<"Element "<<value<<" not present\n";
        return -1;
    }
    PREV->next = PTR->next;
    int tc = PTR->val;
    delete PTR;
    free(PTR);
    return tc;
}

bool sublistSearch(Node *h1,Node *h2){
    if(h1==NULL && h2==NULL)
        return true;
    else if((h1==NULL && h2!=NULL) || (h1!=NULL && h2==NULL))
        return false;
    else{
        while(h2){
            Node *PTR = h2;
            Node *TRCK = h1;
            while(TRCK && PTR && (TRCK->val==PTR->val)){
                PTR=PTR->next;
                TRCK=TRCK->next;
            }
            if(!TRCK)
                return true;
            h2=h2->next;
        }
        return false;
    }
}

int main(int argc, char const *argv[]){

    Node *head=NULL;
    for(int i=0;i<9;i++){
        insert(head,new Node(i+1));
    }
    display(head);
    findMiddle(head);
    deletionByVal(head,10);
    display(head);
    
    Node *h2 = NULL;

    for(int i=4;i<8;i++)
        insert(h2,new Node(i+1));
    sublistSearch(h2,head)?cout<<"YES":cout<<"NO";

    return 0;
}
