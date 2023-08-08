#include<iostream>
using namespace std;
bool ispossible(int arr[],int n,int m,int mid)
{
    int student=1;
    int pagecount=0;
    for(int i=0;i<n;i++){
    if(pagecount+arr[i]<=mid)
    {
        pagecount=pagecount+arr[i];
    }
    else{
        student++;
        if(student>m  || arr[i]>mid)
        {
            return false;
        }

      }
    }
    return true;
}
int allocation(int arr[],int n,int m)
{   
    int s=0;
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum=sum+arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(ispossible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;

}
int main()
{
    int arr[4]={10,20,30,40};
    cout<<allocation(arr,4,2);
    return 0;
    
}