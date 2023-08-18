#include <iostream>
using  namespace std;
void fun(int a[]) {
    cout << a[0] << " ";
}
int main(){
     
  /*   float f = 10.5;
     float p = 2.5;
     float *ptr = &f;
     (*ptr)++;
     *ptr = p;
        cout<<*ptr<<" "<< f <<" "<< p <<endl;
        */


       /*char ch = 'a';
       char *ptr = &ch;
       ch++;
       cout<<*ptr;*/


             /*  int a = 7;
        int *c = &a;
            c = c + 3;
        cout<< c << endl;*/




                    /* double a = 10.54;
                double *d = &a;
                    d  = d + 1;
                    cout  << d << endl;*/


             /*  int a[5];
                int *c;
                cout<<sizeof(a)<<" "<<sizeof(c)<<endl;*/

              /*  int a[] = {1, 2, 3, 4};
             cout << *(a) << " " << *(a+1);



                 */

/*char s[]= "hello";
char *p = s;
cout << s[0] << " " << p[0];*/



/*int  no[5];
int *p;
p= no;
*p = 10;
p=&no[2];
*p = 20;
p--;
*p = 30;
p = no + 3;
*p = 40;
p = no;
*(p+4) = 50;
 for(int i = 0;i<5;i++){
    cout<<no[i]<<" ";
 }*/



    int a[] = {1, 2, 3, 4};
    fun(a + 1);
    cout << a[0];





                    return 0;

}