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
int sizeElem=0;
void push(Node** head,Node** middle,long x){
    Node* temp = new Node(x);
    sizeElem+=1;
    if(!*head){
        *head = temp;
        *middle = *head;
    }
    else{
        (*head)->prev = temp;
        temp->next = (*head);
        *head = temp;
        if(sizeElem%2!=0 && (*middle==*head)){
            
            if(*middle){
                
                *middle = (*middle)->prev;
            }
        }else if(sizeElem%2==0 && (*middle!=(*head)->next)){
            if(*middle){
                
                *middle = (*middle)->prev->prev;
            }
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
void printMiddle(Node** middle){
    if(!*middle){
        cout<<-1<<"\n";
        return;
    }
    cout<<(*middle)->data<<"\n";
}

void insertAtMiddle(Node** head, Node** middle,long x){
    Node* temp = new Node(x);
    sizeElem++;
    if(!*middle){
        *middle = temp;
        temp = *head;
        return;
    }else{
        temp->next = (*middle)->next;
        temp->prev =(*middle);
        (*middle)->next = temp;
        
        if(sizeElem%2!=0 && (*middle==*head)){
            *middle = (*middle)->prev;
        }else if(sizeElem%2==0 && (*middle!=(*head)->next)){
                *middle = (*middle)->prev->prev;
        }
        
        
    }
}
long removeFromMiddle(Node** head,Node** middle){
    Node* temp = *head;
    if(*middle == *head){
        cout<<(*middle)->data<<"\n";
        *middle = *head = NULL;
        sizeElem = 0;
    }
    if(!*head || !*middle){
        cout<<"-1\n";
        return -1;
    }else{
            (*middle)->prev->next = (*middle)->next;
            sizeElem--;
            cout<<(*middle)->data<<"\n";
            if(sizeElem%2!=0 && (*middle==*head)){
                *middle = (*middle)->prev;
            }else if(sizeElem%2==0 && (*middle!=(*head)->next)){
                    *middle = (*middle)->prev->prev;
            }
            return -1;
    }
        
}

int main(){
    Node* head = NULL;
    Node* middle = NULL;
    
    int N,Q,type;
    long elem;
    cin>>N;
    while(N){
        cin>>elem;
        push(&head,&middle,elem);
        N--;
    }
    cin>>Q;
    while(Q){
        cin>>type;
        switch(type){
            case 1:
                cin>>elem;
                push(&head,&middle,elem);
                break;
            case 2:
                cin>>elem;
                insertAtMiddle(&head,&middle,elem);
                break;
            case 3:
                cout<<getTop(head)<<"\n";
                break;
            case 4:
                removeFromMiddle(&head,&middle);
                break;
            case 5:
                printMiddle(&middle);
                break;
        }
        Q--;
    }

    
}