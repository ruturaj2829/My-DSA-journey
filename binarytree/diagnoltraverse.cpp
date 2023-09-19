#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
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
vector<int> diagonaltraverse(node*root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        while(temp){
            if(temp->left){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}
int main() {
    // Creating a binary tree
    struct node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->right->left = new node(-1);
    root->right->right = new node(14);

    // Call the diagonaltraverse function to perform diagonal traversal
    vector<int> diagonalTraversal = diagonaltraverse(root);

    // Print the diagonal traversal result
    cout << "Diagonal Traversal of the binary tree is: ";
    for (int i = 0; i < diagonalTraversal.size(); ++i) {
        cout << diagonalTraversal[i] << " ";
    }

    return 0;
}
