#include<iostream>
#include<vector>
using namespace std;
void solve(int i , vector<int>& arr ,  vector<int>curr , vector<vector<int>>& ans ){

    //base condtition
    if(i >= arr.size()){
        ans.push_back(curr);
        return;
    }
    //recursive calll to exclude
    solve(i+1,arr,curr,ans);
    //recursive call to include
 curr.push_back(arr[i]);
  solve(i+1,arr,curr,ans);

}
vector<vector<int>>powerset(vector<int>arr){

        vector<vector<int>> ans;
        vector<int>curr;
        int i = 0;
        solve(i,arr,curr,ans);
      

      return ans;
}
int main()
{
    // Taking user input.
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
       cin >> arr[i];

    // Calling powerSet() function to generate the power set of   'ARR'.
    vector<vector<int>> ans = powerset(arr);

    // Printing the power set.
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
/*The input is read, and n is 3. The array arr is filled with the values [1, 2, 3].

The powerset function is called with arr = [1, 2, 3].

Inside the powerset function:

The solve function is called with i = 0, arr = [1, 2, 3], curr = [], and ans as an empty vector.
Inside the solve function for the first call (i = 0):

Since i (0) is less than the size of arr (3), the first recursive call is made with i = 1, arr, curr, and ans.
The first recursive call excludes the element at index 0 (1) from the current subset. The curr vector remains [].
Inside the solve function for the second call (i = 1):

Again, i (1) is less than the size of arr (3), so the first recursive call is made with i = 2, arr, curr, and ans.
The second recursive call includes the element at index 1 (2) in the current subset. The curr vector becomes [2].
Inside the solve function for the third call (i = 2):

Now, i (2) is equal to the size of arr (3), so the base condition is met.
The current subset (curr) is [2], and it is pushed into the ans vector.
Back to the second call (i = 1):

The current subset (curr) is [2], and it was modified in the previous step.
The second recursive call (to include the element at index 1) is complete.
Back to the first call (i = 0):

Now, the first recursive call (to exclude the element at index 0) is complete as well.
The current subset (curr) is still [].
The solve function returns to the powerset function.

The power set generation for the current index (0) is complete.
The generated power set for the entire array [1, 2, 3] is [[2], [], [2, 3], [3], [1, 2], [1], [1, 2, 3], []].

The main function then prints this power set in the required format.*/
