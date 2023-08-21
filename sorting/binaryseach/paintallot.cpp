#include<iostream>
using namespace std;
bool ispossible(int arr[],int k,int n,int mid){
    int painter = 1;
    int boardsum = 0;
    for(int i = 0;i<n;i++){
        if(boardsum + arr[i]<=mid){
            boardsum=arr[i];
        }
        else{
            painter++;
            if(painter > k || arr[i] > mid){
                return false ;
            }
            painter = arr[i];
        }
    }
    return true;
    
}

int boardallocation(int arr[],int k,int n){

    int s = 0;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(ispossible( arr, k , n, mid)){
           ans = mid;
           e = mid-1; 
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
    
}

int main(){
int n=4 ; int k =  2 ;
int a[4]={5,5,5,5};
cout<<boardallocation(a,2,4)<<endl;

    return 0;

}