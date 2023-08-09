#include <iostream>
#include <algorithm>
using namespace std;
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}

void selectionsort(int arr[],int n){
for(int i=0;i<n;i++){
    int mini = i;
    for(int j = i+1;j<n;j++){
        if(arr[j]<arr[mini]){
            mini = j ;
        }
    }
    swap(arr[i],arr[mini]);}
}

 
// Driver program
int main()
{
    int arr[] = { 59, 25, 12,10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function Call
    selectionsort(arr, n);
    cout<<"sorted array"<<endl;
    printArray(arr, n);
    return 0;
}