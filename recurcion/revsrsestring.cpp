#include <iostream>
using namespace std;
void reversestring(string& str , int i , int j ){


    if (i  >  j  ) 
    return;
     swap(str[i],str[j]);
     i++;
     j--;
     reversestring(str,i,j);

}
int main(){
     string name =  "raj" ;
     cout<<endl;
     reversestring(name , 0 , name.length()-1);
    cout<<name;

     return 0;
}