#include <iostream>
using namespace std;

struct node{
    int key;
    node* next;
};

int main(){
    node *head = new node;
    head->key = 5;
    head->next = NULL;

    cout<<head->key<<"\n";
    cout<<(*head).key<<"\n";
    return 0;
}

// head->key
// (*head).key
