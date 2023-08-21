#include <iostream>
using namespace std;
int factorial(int n ){
    if (n==0){           // base case if mandotary
        return 1;
    }
    int choti = factorial(n-1);
    int badi = n * choti ; 
    return badi ; 
}
int main(){
    int n ;
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;



    return 0;
}