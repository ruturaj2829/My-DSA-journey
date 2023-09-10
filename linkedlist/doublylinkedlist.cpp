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
void print(Node* &head){
    Node* temp = head ;
    while(temp!= NULL){
        cout<<temp->data<<" " ;
        temp = temp->next;
    }
    cout<<endl;
}
int getlength(Node* &head){
     Node* temp = head ;
     int len  = 0;
    while(temp!= NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node*temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node*temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head  = temp;
    }
   
}
void insertattail(Node* &tail,Node* &head,int d){
    
    if(head==NULL){
        Node*temp = new Node(d);
        tail = temp;
        head = temp;   
    }
    else{
        Node*temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
   
    
}
void insertatpos(Node* &head , Node* &tail , int position , int d){
    if(position==1){
      insertathead(head,tail,d);
      return;  
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    //inserting at tail
    if(temp->next == NULL){
        insertattail(tail,head,d);
        return;
    }
    //for mid
    Node* toadd = new Node(d);
    toadd -> next = temp->next;
    temp -> next -> prev = toadd;
    temp->next = toadd;
    toadd -> prev = temp;
}
void deletenode(int pos , Node* &head){
   
   //delete first pos;
    if(pos==1){
        Node* temp = head;
        temp ->next -> prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    //delete at anypos
    else{
        Node*curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr -> prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
   
   
}
int main(int argc, char const *argv[])
{
    
    Node* head= NULL;
    Node* tail = NULL;
    print(head);
    cout<<endl;
   // cout<<getlength(node1)<<endl;
    insertathead(head,tail,20);
    
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertattail(tail,head,50);
    print(head);
    insertatpos(head,tail,2,100);
    print(head);
    insertatpos(head,tail,3,101);
    insertatpos(head,tail,4,102);
    print(head);

    deletenode(1,head);
    print(head);
    
    deletenode(5,head);
    print(head);
    
    deletenode(7,head);
    print(head);
    


    

    return 0;
}



