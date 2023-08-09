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
void bubblesort(int arr[],int n){
    int i,j;
    for(i=1;i<n;i++){
        bool swapped = false;
        for(j=0;j<n-1;j++)
        if(arr[j]>arr[j+1]){
            swap(arr[j+1],arr[j]);
            swapped = true;
        }
        if(swapped==false){
            break;
        }

    }
}
int main()
{
    int arr[] = { 59, 25, 12,10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function Call
    bubblesort(arr, n);
    cout<<"sorted array"<<endl;
    printArray(arr, n);
    return 0;
}