
#include <iostreAM>
using namespace std;
int getpivot(int arr[],int n){
    int s=0;
    int e=n-1;
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
    return arr[s];
}
int main(){
int arr[5]={8,10,17,1,2};
int result =  getpivot(arr,5);
cout<< "pivot is "<< result << endl;

    return 0;
}

