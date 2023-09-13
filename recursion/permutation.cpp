#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums, int i, vector<vector<int>>& ans) {
    // Base case
    if (i >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        solve(nums, i + 1, ans);
        swap(nums[i], nums[j]); // Backtrack by restoring the original state
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int i = 0;
    solve(nums, i, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
