#include <iostream>
using namespace std;


int swapalternate(int arr[],int size){
   for(int i=0;i<size;i+=2){
    if(i+1<size){
        swap(arr[i],arr[i+1]);
        
    }

}

}

int main(){

int even[8]={4,5,9,7,8,6,3,2,};
int odd[5]={4,5,6,7,2};
swapalternate(even,8);
cout<<" "<<swapalternate(even,8)<<endl;




    return 0;
}
