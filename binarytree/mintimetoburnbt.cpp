#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};
node* parentnode(int target , map<node*,node*> &parent , node*root){

    node * res  = NULL;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->data == target){
            res = temp;
        }
        if(temp-> left){
            parent[temp->left] = temp;
            q.push(temp->left);
        }
         if(temp-> right){
            parent[temp->right] = temp;
            q.push(temp->right);

        }
        
    }
    return res;
}
int burntree(node* root,int target , map<node*,node*> &parent ,int &ans){

    bool flag = 0;
    map<node* , bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()){

        int size  =q.size();
        for(int i = 0 ;i<size ; i++ ){
            node*temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                
                flag = 1;
                q.push(temp->left);
                visited[temp->left] = 1 ;

            }
            if(temp->right && !visited[temp->right]){
               
                flag = 1;
                q.push(temp->right);
                visited[temp->right] = 1 ;
                
            }
            if(parent[temp] && !visited[parent[temp]]){
              
                flag = 1;
                q.push(parent[temp]);
                visited[parent[temp]] = 1 ;
                
            }

        }
        if(flag ==1){
            ans++;
        }

    }
    return ans;
}
int mintime ( node* root , int target){


    map<node*,node*> parent;
    int ans = burntree(root,target,parent,ans);
    return ans;
}
int main() {
    // Create a binary tree
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    int target = 50; // Change this to the target node you want to burn

    int result = mintime(root, target);
    cout << "Minimum time to burn the tree from node " << target << " is: " << result << endl;

    // Free the allocated memory for the tree nodes (optional but recommended)
    // You can write a separate function to deallocate memory if needed.

    return 0;
}

