#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};
Node *start = NULL;
void insert(int x){
    Node *temp = new Node(x);
    if(!start){
        start = temp;
    }else{
        Node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = temp;
    }
}
int main(int argc, char const *argv[]){
    
    for(int i=1;i<5;i++)
        insert(i);

    Node* tc = start->next;
    Node *temp = start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = tc;

    Node* pt1,*pt2;
    pt1 = pt2 = start;
    

    while((pt2!=NULL && pt2->next!=NULL)){
        pt1 = pt1->next;
        pt2 = pt2->next->next;
        if(pt2==pt1)
            break;
    }
    // cout<<pt1->data<<" "<<pt2->data<<"\n";
    if(pt2!=NULL){
        cout<<"Loop";
    }else
        cout<<"No Loop";
    return 0;
}
