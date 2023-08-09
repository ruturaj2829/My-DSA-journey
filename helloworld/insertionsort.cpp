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
void insertionsort(int arr[],int n){
    int i,j , element;
    for(i=1;i<n;i++){
        element = arr[i];
        j = i - 1 ;
        while(j>=0 && arr[j]>element){
                arr[j+1] = arr[j];
                j = j - 1 ;

        }
        arr[j+1] = element ;
    }

}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionsort(arr, N);
    printArray(arr, N);
 
    return 0;
}