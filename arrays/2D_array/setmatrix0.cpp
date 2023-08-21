#include <iostream>
#include <vector>
using namespace std;


void setZeros(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> row(n, false);
    vector<bool> col(m, false);

    // Mark rows and columns with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Set elements to zero based on marked rows and columns
    for (int i = 0; i < n; i++) {
        if (row[i]) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;  // Use assignment operator to set elements to zero
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (col[j]) {
            for (int i = 0; i < n; i++) {
                matrix[i][j] = 0;  // Use assignment operator to set elements to zero
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    setZeros(matrix);

    // Print modified matrix
    for (const auto &row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
