
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;

vector <int> primesNumber;
void SieveOfEratosthenes(){
    
    vector<bool>prime(MAX,true);
    for (int p=2; p*p<=MAX; p++){
        if (prime[p] == true){
            primesNumber.push_back(p);
            for (int i=p*2; i<=MAX; i += p)
                prime[i] = false;
        }
    }
}
 

long findPrimesProduct(int n){

    int product;

    for (int i=0 ; primesNumber[i] <= n/2; i++){
        int diff = n - primesNumber[i];
        if (binary_search(primesNumber.begin(), primesNumber.end(), diff))
            product = primesNumber[i]*diff<product?primesNumber[i]*diff:product;
    }
    return product;
}
 
// Driver code
int main()
{
    // Finding all prime numbers before limit
    SieveOfEratosthenes();
    int N;
    cin>>N;
    vector<long>arr(N);
    vector<long>answ;
    for(int i=0;i<N;i++){
        cin>>arr[i];    
        answ.push_back(findPrimesProduct(arr[i]));
    }
    for(auto e:answ)
        cout<<e<<" ";
    cout<<"\n";
    return 0;
}