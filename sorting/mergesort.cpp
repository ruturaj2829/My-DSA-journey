#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> arr, int s, int e, int mid) {
    int i = s;
    int j = mid + 1;
    vector<int> ans;

    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            ans.push_back(arr[i]);
            i++;
        } else {
            ans.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        ans.push_back(arr[i]);
        i++;
    }
    while (j <= e) {
        ans.push_back(arr[j]);
        j++;
    }
    return ans;
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    
    // Update the original array with the sorted values from merge function
    vector<int> merged = merge(arr, s, e, mid);
    for (int i = s; i <= e; i++) {
        arr[i] = merged[i - s];
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
