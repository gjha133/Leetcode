class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;
        vector<int> dp (n+1, -1);
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, f(i, d, arr, dp));
        }
        
        return ans;
    }
    
    int f(int i, int d, vector<int>& arr, vector<int>& dp)
    {
        int n = arr.size();
        int ans = 1;
        
        if(dp[i] != -1) return dp[i];
        
        // Jump Right
        for(int j = i + 1; j <= min(i+d, n-1) and arr[i] > arr[j]; j++)
            ans = max(ans, 1 + f(j, d, arr, dp));
        
        // Jump left
        for(int j = i - 1; j >= max(0, i-d) and arr[i] > arr[j]; j--)
            ans = max(ans, 1 + f(j, d, arr, dp));
        
        return dp[i] = ans;
    }
};