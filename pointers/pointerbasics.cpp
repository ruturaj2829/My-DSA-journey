#include <iostream>
using namespace std;
int main(){
  /*  int i = 5;
  int *p = &i;  

    cout << *p ;
    
*/
   //both indicate same ptr
    int num = 5;
    int a = num;
    a++;
     cout << num<<endl;
      
      int  * p = &num;
      cout<<*p <<endl;
      (*p)++;
      cout<<*p;
         


   // how to copy  ptrs
    int *q = p;
    cout<<p<<""<<q<<endl;
    cout<<*p<<""<<*q<<endl;

    //imp content
    int r = 3;
    int *t = &r;
    *t = *t + 1;
    cout<<(*t)<<endl;
    
     cout<<(t)<<endl;
    t = t+1; 
    cout<<t<<endl;

   return 0;
}