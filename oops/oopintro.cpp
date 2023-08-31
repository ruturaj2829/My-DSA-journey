#include<iostream>
using  namespace std;
 


 class hero{
  private://cant access outside of class;
   //how to access private //
   //using getter,setter
  int health;  
  char level;
   
  



   public://can access  outside class;
 
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


 };
 int main (){
     
    hero h1;//object creation
     // cout<<sizeof(h1);
      hero ramesh;//object creation ;
     // cout<<ramesh.health<<endl;
     // cout<<ramesh.level<<endl;
   //use setter>
  cout<<ramesh.gethealth()<<endl;
  ramesh.sethealth(70);
  cout<<ramesh.gethealth()<<endl;
  // use getter>
  //dynamically representation
  hero *b = new hero;
 b->setlevel('A');
 b->sethealth(70);

  cout<<(*b).getlevel()<<endl;
  cout<<(*b).gethealth()<<endl;

  
     

     return 0;
 }