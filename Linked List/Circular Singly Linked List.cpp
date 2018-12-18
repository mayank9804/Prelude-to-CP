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
void insertNode(Node *&head,Node *newNode){
    if(!head){
        head = newNode;
        head->next = head;
    }else{
        newNode->next = head;
        Node *PTR = head;
        while(PTR->next!=head)
            PTR = PTR->next;
        PTR->next = newNode;
    }
}
void display(Node *head){
    if(!head){
        cout<<"Empty Circular Linked List\n";
        return ;
    }
    Node *PTR = head;
    do{
        cout<<PTR->val<<" ";
        PTR = PTR->next;
    }while(PTR!=head);
    cout<<"\n";
}
void insertSorted(Node *&head,Node *curr,Node *newptr){

    if(!curr){
        curr = newptr;
        curr->next = newptr;
        head = curr;
    }else{
        Node *PTR = curr;
        Node *MAX = PTR;
        Node *MIN = PTR;

        while(PTR->next!=curr){
            if(PTR->val >= MAX->val)
                MAX = PTR;
            if(PTR->val < MIN->val)
                MIN = PTR;
            PTR = PTR->next;
        }
        if(PTR->val >= MAX->val)
            MAX = PTR;
        if(PTR->val < MIN->val)
            MIN = PTR;
        PTR = curr;
        bool went = false;
        while(!(newptr->val >=PTR->val && newptr->val <=PTR->next->val)){
            went  = true;
            PTR = PTR->next;
            if(PTR==curr)
                break;
        }
        if(PTR!=curr && went){
            newptr->next = PTR->next;
            PTR->next = newptr;
        }else if(PTR==curr && !went){
            newptr->next = PTR->next;
            PTR->next = newptr;
        }else if(newptr->val>= MAX->val){
            newptr->next = MAX->next;
            MAX->next = newptr;
        }else if(newptr->val<=MIN->val){
            Node *temp = MIN->next;
            while(temp->next!=MIN){
                temp = temp->next;
            }
            
            newptr->next = temp->next;
            temp->next = newptr;
            head = newptr;
        }
    }
}
int main(int argc, char const *argv[]){
    
    Node *head = NULL;
    for(int i=1;i<9;i+=2){
        // 1 3 5 7 
        insertNode(head,new Node(i));
    }
    display(head);
    insertSorted(head,head->next,new Node(3));
    display(head);
    return 0;
}
