#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node*next;
    Node* prev;
    //constructor
    Node(int data){
        this ->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
       int value = this->data;
       if(next!= NULL){
        delete next;
        next = NULL;
       }
       cout<<"memoryfree"<<endl;
    }
};