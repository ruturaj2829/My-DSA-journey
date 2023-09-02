#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node*next;
    Node* prev;
    Node(int data){
        this ->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node* head){
    Node* temp = head ;
    while(temp!= NULL){
        cout<<temp->data<<" " ;
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    Node* node1 = new Node(10);
    print(node1);
    Node* node2= new Node(20);
    print(node2);

    return 0;
}



