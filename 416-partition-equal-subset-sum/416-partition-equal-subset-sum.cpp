class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        if(totalSum&1) return false;
        return subsetSumToK(nums.size(), totalSum/2, nums) == true;
    }
    
    bool sumK(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(k == 0) return true;
        if(i == 0) return arr[i] == k;
        if(dp[i][k] != -1) return dp[i][k];

        bool notTake = sumK(i-1, k, arr, dp);
        bool take = false;
        if(k >= arr[i]) take = sumK(i-1, k - arr[i], arr, dp);

        return dp[i][k] = notTake or take;
    }

    bool subsetSumToK(int n, int k, vector<int> &arr) 
    {
        vector<vector<int>> dp (n, vector<int> (k+1, -1));
        return sumK(n-1, k, arr, dp);
    }


};