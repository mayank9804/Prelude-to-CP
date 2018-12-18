#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};
void insertLast(Node *&head,Node *&middle,Node *newNode){
    size++;
    if(!head){
        head = newNode;
        middle = head;
    }else{
        newNode

    }
}