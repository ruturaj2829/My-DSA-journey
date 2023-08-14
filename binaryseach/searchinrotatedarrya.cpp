#include<iostream>
using namespace std;


int binarysearch(int arr[],int start,int end,int key)
{
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key)
        {
            return mid;
        }
        if(key>arr[mid])
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return e;
    
}
int getpivot(int arr[],int start,int end){
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int getpos(int arr[],int n,int key)
{
    int pivot=getpivot(arr,0,n-1);
    {
        if(key>=arr[pivot] && key<=arr[n-1])
        {
            return binarysearch(arr,pivot,n-1,key);
        }
        else{
            return binarysearch(arr,0,pivot-1,key);
        }
    }
    
}

int main(){
    int arr[5]={6,7,1,2,3};
    
    cout<<"index : "<<getpos(arr,5,3);
    return 0;
}