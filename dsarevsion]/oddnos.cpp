 #include <iostream>
using namespace std;
int main(){
    int a[5] = {1,5,3,4,19};
   int  n = 5;
   
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {   
            
           if(max<a[i]){
            max = a[i];}

            
        }
       
    }
   cout<<max;
    return 0;
}
 