#include <iostream>
#include <cmath>
using namespace std;

int binarysearch(int arr[], int s, int e, int key) {
    if (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            return binarysearch(arr, mid + 1, e, key);
        } else {
            return binarysearch(arr, s, mid - 1, key);
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    int x = 2;
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int result = binarysearch(arr, 0, n - 1, x);
    cout << "Element found at index: " << result << endl;

    return 0;
}
