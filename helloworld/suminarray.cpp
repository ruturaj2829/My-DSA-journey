#include <iostream>
#include <numeric>
using namespace std;
int getsum(int num[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
       sum+=num[i];


    }
return sum;

}
int main(){
int num[5]= {12,13,15,17,18};
int n = sizeof(num)/sizeof(num[0]);
cout<< "  sum of digits is"   <<    getsum(num,n) << endl;


return 0;


}



