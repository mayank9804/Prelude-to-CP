#include <bits/stdc++.h>
using namespace std;

struct Node{
    long data;
    Node* next;
    Node* prev;

    Node(long x):data(x){
        this->next = NULL;
        this->prev = NULL;
    }
};
long sizeElem = 0;

void push(Node *&head,Node *&middle,Node *newNode){
    
    sizeElem+=1;

    if(!head){
        head = newNode;
        middle = head;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        
        if(sizeElem%2!=0){
            middle = middle->prev;
        }
    
        
    }
}
long getTop(Node* head){
    if(!head){
        return -1;
    }else{
        return head->data;
    }
}
void printMiddle(Node *middle){
    if(!middle){
        cout<<-1<<"\n";
        return;
    }
    cout<<middle->data<<"\n";
}

void insertAtMiddle(Node *&head, Node *&middle,Node *newNode){
    
    sizeElem++;
    if(!middle){
        head = newNode;
        middle = newNode;
    }else{
        newNode->next = middle;
        newNode->prev =middle->prev;
        if(middle->prev)
            middle->prev->next = newNode;
        middle->prev = newNode;
        
        middle = middle->prev;
    }
}
long removeFromMiddle(Node *&head,Node *&middle){
    
    if(middle == head && !head->next){
        cout<<middle->data<<"\n";
        middle = head = NULL;
        sizeElem = 0;
    }
    else if(!head || !middle){
        cout<<"-1\n";
        return -1;
    }else{
            
            sizeElem--;
            cout<<middle->data<<"\n";

            middle->prev->next = middle->next;
            if(middle->next)
                middle->next->prev = middle->prev;
            
                if(sizeElem%2==0)
                    middle = middle->next;
                else
                    middle = middle->prev;
            
            
            return -1;
    }
        
}

int main(int argc,char **argv){
    
    Node* head = NULL;
    Node* middle = NULL;
    
    int N,Q,type;
    long elem;
    cin>>N;
    while(N){
        cin>>elem;
        push(head,middle,new Node(elem));
        N--;
    }
    cin>>Q;
    while(Q){
        cin>>type;
        switch(type){
            case 1:
                cin>>elem;
                push(head,middle,new Node(elem));
                break;
            case 2:
                cin>>elem;
                insertAtMiddle(head,middle,new Node(elem));
                break;
            case 3:
                cout<<getTop(head)<<"\n";
                break;
            case 4:
                removeFromMiddle(head,middle);
                break;
            case 5:
                printMiddle(middle);
                break;
        }
        Q--;
    }

    
}