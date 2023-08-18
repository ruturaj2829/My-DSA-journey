#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral(vector<vector<int>> matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    int startingrow = 0;
    int endingrow = n - 1;
    int startingcol = 0;
    int endingcol = m - 1;
    int count = 0;
    int total = n * m;
    vector<int> ans;

    while (count < total)
    {
        // Traverse the top row
        for (int i = startingcol; count < total && i <= endingcol; i++)
        {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

        // Traverse the right column
        for (int i = startingrow; count < total && i <= endingrow; i++)
        {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        // Traverse the bottom row
        for (int i = endingcol; count < total && i >= startingcol; i--)
        {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;

        // Traverse the left column
        for (int i = endingrow; count < total && i >= startingrow; i--)
        {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    return ans;
}

int main()
{
    // Create a sample matrix
    vector<vector<int>> matrix = {
        {1, 2, 3,4,5,6},
        {4, 5, 6,4,5,6},
        {7, 8, 9,4,5,6}
    };

    vector<int> result = spiral(matrix);

    // Print the spiral order traversal
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
