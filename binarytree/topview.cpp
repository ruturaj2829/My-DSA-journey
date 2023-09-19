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
void topview(struct node*root){
    if(root == NULL){
        return;
    }
    queue<pair<struct node*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while(!q.empty()){
       pair<struct node*,int>temp = q.front();
       q.pop();
       node* frontnode = temp.first;
       int hd =temp.second;
       if(mp.find(hd)==mp.end()){
           mp[hd] = frontnode->data;
       }
       if(frontnode->left){
        q.push(make_pair(frontnode->left,hd-1));
       }
        if(frontnode->right){
        q.push(make_pair(frontnode->right,hd+1));
       }


    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}
int main() {
    // Creating a binary tree
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    cout << "Top View of the binary tree is: ";
    topview(root);

    return 0;
}
