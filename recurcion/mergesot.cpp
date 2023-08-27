#include <iostream>
#include <vector>

class Solution {
private:
    void merge(std::vector<int>& nums, int s, int e, int mid) {
        std::vector<int> temp;
        int i = s;
        int j = mid + 1;

        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= e) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = s; k <= e; k++) {
            nums[k] = temp[k - s];
        }
    }

    void mergesort(std::vector<int>& nums, int s, int e) {
        if (s < e) {
            int mid = s + (e - s) / 2;
            mergesort(nums, s, mid);
            mergesort(nums, mid + 1, e);
            merge(nums, s, e, mid);
        }
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> sorted = solution.sortArray(nums);
    
    std::cout << "Sorted array: ";
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
