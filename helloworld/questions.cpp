#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
   int a[4] = {100,50,20,10};
   int amount ,i,temp;
   cout<< "Enter the Amount of cash= ";
   cin>>amount;
   amount=temp ;
   for(i=0;i<4;i++){
    cout<<a[i]<<"notes is"<<temp/a[i]<<endl;
    temp=temp % a[i];
   }

   
  

    return 0;
}
