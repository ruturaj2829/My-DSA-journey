#include<iostream>
using namespace std;
#include <stack>
#include<vector>
class Solution 
{
private:
    bool knows(vector<vector<int> >& M, int a, int b) 
    {
        if (M[a][b] == 1) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for (int i = 0; i < n; i++) 
        {
            s.push(i);
        }
        while (s.size() > 1) 
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (knows(M, a, b)) 
            {
                s.push(b);
            }
            else 
            {
                s.push(a);
            }
        }
        int ans = s.top();
        int zerocnt = 0;
        for (int i = 0; i < n; i++) 
        {
            if (M[ans][i] == 0)
                zerocnt++;
        }
        if (zerocnt != n)
            return -1;

        int onecnt = 0;
        for (int i = 0; i < n; i++) 
        {
            if (M[i][ans] == 1)
                onecnt++;
        }
        if (onecnt != n - 1)
            return -1;
        return ans;
    }
};
int main() 
{
    // Example usage
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 0},
        {1, 1, 0}
    };

    int n = M.size();
    
    Solution solution;
    int celebrity = solution.celebrity(M, n);
    
    if (celebrity != -1) 
    {
        cout << "The celebrity is person " << celebrity << endl;
    } 
    else 
    {
        cout << "There is no celebrity in the party." << endl;
    }

    return 0;
}