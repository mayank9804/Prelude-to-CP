#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    
    int A[4][4] ={{1,2,1,3},{0,2,3,3},{1,0,2,2},{1,2,2,1}};
    int pA[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j && i==0)
                pA[i][j]=A[i][j];
            else if(i==0 && j>0)
                pA[i][j]=pA[i][j-1]+A[i][j];
            else if(j==0 && i>0)
                pA[i][j]=pA[i-1][j]+A[i][j];
            else
                pA[i][j]=pA[i-1][j]+pA[i][j-1]-pA[i-1][j-1]+A[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<pA[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
