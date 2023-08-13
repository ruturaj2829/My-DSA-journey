#include<iostream>
#include<vector>
using namespace std;
vector < int > sortedArray(int a[], int n,int b[], int m) {
    int i=0;
    int j=0;
    vector<int> uni;
   
    while(i<n && j<m)
    {   
        if(a[i]<=b[j])
        {
            if(uni.size()==0 || uni.back() !=a[i])
            {
                uni.push_back(a[i]);
               
            }
             i++;
        }
            else{
                if(uni.size()==0 || uni.back() !=b[j])
            {
                uni.push_back(b[j]);
                
            }
            j++;
            }

 }

    
    while(i<n)
    {
        if(uni.back() !=a[i])
        {
            uni.push_back(a[i]);
                
        }
        i++;

    }
    while(j<m){
         if( uni.back() !=b[j])
            {
                uni.push_back(b[j]);
                
            }
            j++;
    }
    return uni;
}

int main(){
int n = 10, m = 7;
  int  a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int b[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Uni = sortedArray(a, 10, b, 7);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Uni)
    cout << val << " ";
  return 0;
}
