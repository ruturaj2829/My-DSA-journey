#include <iostream>
using namespace std;
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
       
    }
}
void insertsort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
  j = i - 1;
  while(j>=0 && arr[j]>key){
    arr[j+1]= arr[j];
    j = j -1 ;
  }
  arr[j+1]= key;
    }
}
int main(){
    int arr[5]={6,2,8,4,10};
    int n = sizeof(arr)/sizeof(arr[0]);
   insertsort(arr,n);
    cout<<"sorted array"<<endl;
    printarray(arr,n);



    return 0;
}