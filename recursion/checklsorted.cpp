#include <iostream>
using namespace std;
bool binary(int arr[] ,int n ){
    
  
    if( n==1 || n==0)
    {
     
        return true;
    }
   
   
    if(arr[0]>arr[1])
    {
        return false;
    }
  
     return binary(arr+1,n-1);
 
    
} 
int main(){
    int arr[5]={1,2,3,77,5};
    int n = 5;
    bool ans= binary(arr,5);
   cout<<" key  " <<  ans;



    return 0;
}