#include <iostream>
#include <conio.h>
using namespace std;
int find_Oddeven(int);//function prototype
int main()
{
    int num;
    cout << "Enter a number to ceck odd or even" << endl;
    cin>>num;//get input from user
    find_Oddeven(num);//calling the function
    getch();
    return 0;
}
//create function
int find_Oddeven(int num){//function definition
if(num&1)
    cout<<num<<"is an odd";
else
    cout<<num<<"is an even";
}