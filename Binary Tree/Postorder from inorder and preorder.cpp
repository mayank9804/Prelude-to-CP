#include <iostream>
using namespace std;

void findPostOrder(int preorder[],int inorder[],int ps,int pe,int is,int ie,int l){

    if(ps>pe || is>ie)
        return;
    
    int ind;
    for(int i=0;i<l;i++){
        if(inorder[i]==preorder[ps]){
            ind = i;
            break;
        }
    }
    int k=ind-is;

    findPostOrder(preorder,inorder,ps+1,ps+k,is,ind-1,l);
    findPostOrder(preorder,inorder,ps+k+1,pe,ind+1,ie,l);
    cout<<preorder[ps]<<' ';
}

int main(){
    int n;
    cin>>n;
    int preorder[n],inorder[n];
    for(int i=0;i<n;i++)
        cin>>preorder[i];

    for(int i=0;i<n;i++)
        cin>>inorder[i];
    
    findPostOrder(preorder,inorder,0,n-1,0,n-1,n);

    
    cout<<'\n';
    return 0;
}