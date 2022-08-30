## Memoization:
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n = nums.size();
vector<vector<int>> dp (n, vector<int> (n+1, -1));
return f(0, -1, nums, dp);
}
int f(int i, int prev_i, vector<int>& nums, vector<vector<int>>& dp)
{
int n = nums.size();
if(i == n) return 0;
if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
int take = INT_MIN;
int notTake = f(i+1, prev_i, nums, dp);
if(prev_i == -1 or nums[i] > nums[prev_i])
take = 1 + f(i+1, i, nums, dp);
return dp[i][prev_i+1] = max(take, notTake);
}
};
```
​