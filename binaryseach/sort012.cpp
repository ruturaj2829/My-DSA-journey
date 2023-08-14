#include <iostream>
#include<algorithm>
using namespace std;
void sort012(int arr[],int n){
      
      int s = 0;
      int e =  n-1;
      int mid = 0;
      
      while (mid<=e)
      {
        
        if(arr[mid]==0){
            swap(arr[mid],arr[s]);
            s++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{

                swap(arr[mid],arr[e]);
                e--;
        }
       
      }
      
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}
int main(){

  int arr[5] = {1,0,2,2,0};
  sort012(arr,5);
  printArray(arr,5);




    return 0;
}