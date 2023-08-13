#include <iostream>
#include <algorithm>
using namespace std;
void insertionsort(int arr[], int n)
{
  int i,j ;
  for(i=0;i<n;i++){ 


     j = i;
     while(j > 0 && arr[j-1] > arr[j]){

            swap(arr[j-1],arr[j]);
            j--;

     }
  }
}
void printarray(int arr[],int n){

   for(int i = 0 ; i<n;i++){
     cout<<arr[i]<<" ";

   }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionsort(arr, N);
    printarray(arr, N);
 
    return 0;
}