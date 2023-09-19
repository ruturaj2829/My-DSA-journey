#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int data ;
    struct node*left;
    struct node*right;
    node(int x){
        data  = x;
        left = right = NULL;
    }
};
bool isidentical(node* r1 ,node*r2){
    //base case
    if(r1==NULL && r2==NULL){
    return true;
    }
    if(r1==NULL || r2!=NULL){
    return false;
    }
   
    bool left = isidentical(r1->left,r2->left);
    bool right = isidentical(r1->right,r2->right);  
    bool value = r1->data==r2->data ;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    // Creating two binary trees
    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);

    struct node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    // Check if the two binary trees are identical
    bool identical = isidentical(root1, root2);

    if (identical) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }

    return 0;
}
