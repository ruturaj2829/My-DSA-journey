#include <bits/stdc++.h> 
using namespace std; // Don't forget to include the namespace

int findKthElement(vector<vector<int>>& matrix, int k) { // Pass the matrix by reference
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int startingcol = 0;
    int startingrow = 0;
    int endingrow  = n - 1;
    int endingcol = m - 1;
    int count = 0;
    while(count < k) {
        for (int i = startingcol; count < k && i <= endingcol; i++) {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
        
        for (int i = startingrow; count < k && i <= endingrow; i++) {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;
        
        for (int i = endingcol; count < k && i >= startingcol; i--) {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;
        
        for (int i = endingrow; count < k && i >= startingrow; i--) {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    return ans[k - 1]; // Return the kth element
}
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 8;
    int kthElement = findKthElement(matrix, k);
    cout << "The " << k << "th element is: " << kthElement << endl;
    return 0;
}


