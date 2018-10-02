#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
map<int,int>CacheMem;
struct Node{
    int data;
    Node* next;
    Node(int n){
        data = n;
        next = NULL;
    }
};
Node* head;
int size = 0;
LRUCache::LRUCache(int N)
{
    CacheMem.clear();
    head = NULL;
    size = N;
     //Your code here
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    
        
    if(CacheMem.find(x)==CacheMem.end()){
     //Your code here
        if(size==0){
            CacheMem.erase(head->next->data);
            if(head->next ==head)
                head = NULL;
            else
                head->next = head->next->next;
            size+=1;
        }
        if(!head){
            head = new Node(x);
            head->next = head;
        }else{
            Node* temp = new Node(x);
            temp->next = head->next;
            head->next = temp;
            head = temp;
        }
        CacheMem[x] = y;
        size--;
    }else{
        
        Node* temp = head->next;
        Node* prev =head;
        do{
            if(temp->data == x){
                if(temp==head){
                    prev->next = head->next;
                    head = prev;
                    break;
                }
                else{
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }while(temp!=head->next);

        if(!head){
            head = new Node(x);
            head->next = head;
        }else{
            temp = new Node(x);
            temp->next = head->next;
            head->next = temp;
            head = temp;
        }
        CacheMem[x] = y;
    }

    // Node* temp = head->next;
    // cout<<"\n";
    // do{
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }while(temp!=head->next);
    // cout<<"\n";
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    if(CacheMem.find(x)==CacheMem.end())
        return -1;
    else{
        Node* temp = head;
        Node* prev = NULL;
        do{
            if(temp->data == x){
                
                if(temp==head){
                    break;
                }
                else{
                    prev->next = temp->next;
                    // delete temp;
                    break;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }while(temp!=head);

        if(temp!=head){
            if(!head){
                head = new Node(x);
                head->next = head;
            }else{
                temp = new Node(x);
                temp->next = head->next;
                head->next = temp;
                head = temp;
            }
        }
        return CacheMem[x];
    }
}
// -1 -1 -1 -1 -1 39 4 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 62 -1 -1 -1 -1 -1 -1 -1 -1 -1 30 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
// -1-1-1-1-1394-1-1-1-1-1-1-1-1-1-1-1-1-1-170-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-126-1-1-1-13-1-1
// 4
// 87
// SET 94 16 SET 93 87 SET 63 22 SET 60 91 SET 41 27 GET 73 GET 12 GET 68 SET 31 83 GET 24 SET 30 36 GET 23 GET 70 SET 57 94 SET 30 43 SET 20 22 GET 38 GET 25 SET 14 71 GET 92 GET 57 SET 71 63 GET 82 SET 85 26 SET 6 37 GET 30 SET 25 58 SET 46 83 GET 68 GET 65 SET 88 51 GET 77 GET 89 GET 4 SET 100 55 GET 61 GET 69 SET 27 13 GET 95 SET 71 96 GET 79 SET 98 2 GET 18 GET 53 GET 2 GET 87 SET 90 66 GET 20 GET 30 SET 98 18 SET 76 82 SET 68 28 GET 98 SET 66 87 GET 84 SET 29 25 SET 30 33 SET 71 20 GET 9 SET 50 41 GET 24 GET 46 GET 52 SET 80 56 GET 65 GET 42 GET 94 GET 35 GET 25 GET 88 GET 44 SET 66 28 SET 33 37 SET 29 38 SET 75 8 SET 96 59 SET 36 38 SET 29 19 SET 29 12 SET 5 77 SET 14 64 GET 7 GET 5 GET 29 GET 70 SET 97 18 GET 44

// 3
// 59
// GET 73 SET 74 38 GET 80 SET 10 62 SET 11 58 SET 67 47 GET 79 GET 42 GET 26 SET 4 70 SET 26 25 SET 85 8 SET 70 32 SET 90 5 GET 66 SET 8 52 GET 63 GET 7 GET 61 SET 55 69 SET 12 46 SET 70 1 SET 27 27 GET 63 SET 32 36 GET 41 GET 50 SET 1 24 GET 33 GET 96 GET 43 SET 63 76 SET 61 80 SET 61 1 GET 98 GET 25 GET 1 SET 32 90 GET 82 GET 80 SET 80 28 SET 95 12 GET 3 GET 15 SET 80 4 GET 64 GET 61 SET 11 55 GET 79 GET 15 GET 54 GET 81 SET 60 55 GET 34 GET 38 SET 45 85 SET 59 74 GET 29 SET 92 90

// -1 -1 -1 -1 -1 -1-1 -1 -1 -1 -1 -1 -1 -1 -1 