#include <iostream>
using namespace std;
int factorial(int y){

int fact = 1;
int i;
for(i=2;i<=y;i++){

 fact=fact*i;
 return fact;

}

}
int main(){

int n,r;
 int ncr,npr;
cout<<"enter the vlaue of n"<<endl;
cin>>n;
cout<<"enter the value of r"<<endl;
cin>>r;
int npr = factorial (n) /factorial (n-r);
int ncr = npr/factorial (r);
cout<< "NCR value is"<< npr<<endl;
cout<<"NCR value is "<< ncr<<endl;
return 0;

}