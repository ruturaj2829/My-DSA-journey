#include <iostream>
using namespace std;
class hero{
  private://cant access outside of class;
   //how to access private //
   //using getter,setter
  int health;  
  char level;
   
  



   public://can access  outside class;

 //NORMAL CONSTRUCTOR
   hero(){
    cout  <<"simple constructor callled" <<endl;
   }
   //PARAMETRIC CONSTRUCTOR
   hero(int health,char level){
    cout<<"this->"<<this<<endl;//o/p-> same add;
    this -> health = health;
    cout<<"this->"<<this<<endl;//o/p-> same add;
    this-> level = level;
   }   //object   //int health;

   //copy CONSTRUCTOR

 
   int gethealth(){
      health;
      return health;
   }
  
   void sethealth(int h){
      health = h;
   }
   
  
   int i;
   char getlevel(){
      return level;

   }
   void setlevel(char ch){
      level =  ch ;
      
   }
   void print(){
    cout<<"health"<< this->health<<endl;
    cout<<"level"<< this->level<<endl;
   }


 };
 int main (){
  //STATICALLY 
   hero ramesh(10,'R');
   cout<<"addd" << &ramesh<<endl;//o/p->same add
  
   //DYNAMICALLY
   hero* h = new hero;
        hero temp(22,'M');//o/p->same add
 //copy constructor;
 
   hero suresh(70,'C');
   hero ritesh(suresh);
  
 ritesh.print();

        



     return 0;
 }