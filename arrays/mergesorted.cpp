#include<iostream>
#include<vector>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = 0;
    int j = 0;
    vector<int> temp;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            temp.push_back(arr2[j]);
            j++;
        } else { // When arr1[i] == arr2[j]
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    while (i < m) {
        temp.push_back(arr1[i]);
        i++;
    }
    
    while (j < n) {
        temp.push_back(arr2[j]);
        j++;
    }

    return temp;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    int m = arr1.size();
    int n = arr2.size();

    vector<int> merged = ninjaAndSortedArrays(arr1, arr2, m, n);

    for(int i = 0; i < merged.size(); i++){
        std::cout << merged.at(i) << ' ';
    }

    return 0;
}
