
// C++ implements genericity with templates
// They are resolved at compile time
// No runtime checks
// Slows compile time but speeds up runtime
//  

#include <iostream>
using namespace std;

template <class T>
T max_custom(T const& t1,T const& t2){
    return t1<t2?t2:t1;
}

template <class T>
class Accum{
    private:
        T total;
    public:
        Accum(T a):total(a){};
        void operator+=(T const& t){
            total = total+t;
        };
        T getTotal(){
            return total;
        }

};
int main(){
    
    cout<<max_custom(22,33)<<"\n";
    cout<<max_custom('x','y')<<"\n";
    cout<<max_custom<double>(22.1,44.9)<<"\n";

    Accum<int>integers(0);
    cout<<integers.getTotal();
    integers+=5;
    cout<<"\n";
    cout<<integers.getTotal();
    cout<<"\n";
    return 0;
}
