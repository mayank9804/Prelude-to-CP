#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int>ARR{0,1,2,2,3,5,5,5,5,5,5};

    // binary_search(L,R,elem)
    // [L,R)
    // returns boolean telling its presence
    cout<<binary_search(ARR.begin(),ARR.begin()+2,2)<<'\n';


    // lower_bound(L,R,elem)
    // [L,R)
    // returns first val greater or equal than elem..
    // returns last iterator if lower bound of elem does not exists 
    cout<<lower_bound(ARR.begin(),ARR.end(),5)-ARR.begin();
    cout<<'\n';
    // upper_bound(L,R,elem)
    // [L,R)
    // return first val greater than elem
    // returns last iterator if lower bound of elem does not exists 
    cout<<upper_bound(ARR.begin(),ARR.end(),10)-ARR.begin();
    cout<<'\n';


    // equal_range returns a pair of iterators (first occurence,last occurence)
    cout<<equal_range(ARR.begin(),ARR.end(),2).first-ARR.begin()<<' ';
    cout<<equal_range(ARR.begin(),ARR.end(),2).second-ARR.begin()<<'\n';
}