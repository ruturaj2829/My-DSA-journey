#include <iostream>
using namespace std;
int getintsquare(int n){
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans;
    while(s<=e){
        int square = mid * mid;
        if(square==n){
            return mid;
        }
        if(square<n){
           ans == mid;
            s=mid+1;
        }
        else{
            e = mid-1;
        }
      mid = s + (e-s)/2;
    }
    return ans;
}
double moreprecision(int n, int precision,int tempsol){
        double factor = 1;
        double ans = tempsol;
        
        for( int i=0;i<precision;i++){
            factor = factor/10;
            for (double j = ans; j * j<n;j=j+factor){
                ans=j;
            }
        }
        return ans;
    }
int main(){
    int n;
    cout<<" enter the number" << endl;
    cin>>n;
    int tempsol  =  getintsquare(n);
    cout<<"answer is"<< moreprecision(n, 3, tempsol)<< endl;
    return 0;


}
