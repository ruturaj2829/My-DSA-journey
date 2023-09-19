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
void findpath(node* root , int &k,int cnt,vector <int> path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    findpath(root->left,k,cnt,path);
    findpath(root->right,k,cnt,path);
     
    int sum = 0;
    for(int i =path.size() ; i>=0 ; i--){
        sum+=path[i];
        if(sum==k){
            cnt++;
        }
    }
    path.pop_back();
}
int sumK(node* root ,int k){
    vector<int> path;
    int cnt =0;
    findpath(root,k,0,path);
    return cnt;

}
int main() {
    // Creating a binary tree
    struct node* root = new node(1);
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right->right = new node(6);

    int k = 5;
    cout << "Count = "
         << sumK(root, k);
    return 0;
}