#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a,b ;
    cout<<"enter the value of a"<<endl;
    cin>>a;
    cout<<"enter the value of b"<<endl;
    cin>>b;
    char op;
    cout<<"enter the opertaion"<<endl;
    cin>>op;
    switch (op)
    {
    case '+':
      cout << a + b << endl;
             break;
    case '-':
      cout << a-b << endl;
            break;
    case '*':
    cout<< a*b << endl;
            break;
    case '/':
       cout<< a/b <<endl;
            break;
    case '%':
       cout<< a%b << endl;
            break;        
    default:cout<< " operation is invalid " << op <<endl;
        break;
    }

           return 0;
}
