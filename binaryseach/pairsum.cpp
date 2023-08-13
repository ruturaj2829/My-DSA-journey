#include<iostream>
using namespace std;
int main(){
    int arr[]={-1,0,-1,2,1,0,4};
    int length1 = sizeof(arr)/sizeof(arr[0]);  
    int s=3;

   for(int i=0;i<length1; i++ )
   {
   		for(int j = i+1; j<length1; j++) {
           
        	if(arr[i] +arr[j] ==s)
            {
            	cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
   }
   
   return 0;
}