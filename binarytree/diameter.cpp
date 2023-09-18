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
pair<int, int> diameterfast(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    // Use std::max to find the maximum of two values at a time
    int max_option1_2 = max(option1, option2);
    int max_of_all = max(max_option1_2, option3);

    pair<int, int> ans;
    ans.first = max_of_all;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(struct node* root){

    return diameterfast(root).first;

}
int main()
{
    // Creating a binary tree
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // Calculate the diameter of the binary tree
    int treeDiameter = diameter(root);

    // Print the result
    cout << "Diameter of the binary tree is: " << treeDiameter << endl;

    return 0;
}
