#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Klargest(const std::vector<int> &a, int k) {
    int n = a.size();
    
    if (k <= 0 || k > n) {
        std::cerr << "Invalid value of k." << std::endl;
        return {};
    }
    
    std::vector<int> arr(a);  // Create a copy of the input vector
    
    std::sort(arr.begin(), arr.end());
    std::vector<int> result;
    
    for (int i = n - 1; k > 0; --i, --k) {
        result.push_back(arr[i]);
    }
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    std::vector<int> a = {3, 1, 5, 2, 4};
    int k = 3;
    
    std::vector<int> result = Klargest(a, k);
    
    std::cout << "K largest elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}
/*
The input vector a is: {3, 1, 5, 2, 4}.

Sorting the input vector: {1, 2, 3, 4, 5}.

Initializing i to n - 1, which is 4.

Loop starts:

Iteration 1: k is still greater than 0.
Push a[4] (largest element) into arr: arr = {5}.
Decrement k to 2 and i to 3.
Iteration 2: k is still greater than 0.
Push a[3] (second largest element) into arr: arr = {5, 4}.
Decrement k to 1 and i to 2.
Iteration 3: k is still greater than 0.
Push a[2] (third largest element) into arr: arr = {5, 4, 3}.
Decrement k to 0 and i to 1.
Loop ends.
Reverse the arr vector: arr = {3, 4, 5}.

Return the arr vector.
                        */