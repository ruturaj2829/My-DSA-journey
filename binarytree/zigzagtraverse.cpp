//with level order
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
vector <int> zigzag(node *root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    queue<node*> q ;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
        int size  = q.size();
        vector <int> ans(size);
        for(int i = 0; i < size ; i++){
            node*front = q.front();
            q.pop();
            int index = lefttoright ? i : size-i-1;
            ans[index] = front ->data;

            if(front->left){
                q.push(front->left);
            }
             if(front->right){
                q.push(front->right);
            }
            
          }  
          //change direction
          lefttoright = !lefttoright;
            for(auto i : ans){
                result.push_back(i);
            }
        }
       
    return result;
}
int main()
{
    // Creating a binary tree
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Traverse the binary tree in zigzag order
    vector<int> zigzagResult = zigzag(root);

    // Print the result
    cout << "Zigzag (Level Order) Traversal: ";
    for (int num : zigzagResult)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

