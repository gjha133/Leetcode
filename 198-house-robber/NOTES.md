int notpick = 0 + robber(i+1, n, nums, dp);
return dp[i] = max(pick, notpick);
}
};
```
​
Tabulation:
```
class Solution {
public:
int rob(vector<int>& nums) {
int n = nums.size();
if(!n) return 0;
vector<int> dp(n);
dp[0] = nums[0];
for(int i = 1; i<n; i++)
{
int take = nums[i];
if(i > 1) take += dp[i-2];
int nottake = dp[i-1];
dp[i] = max(take, nottake);
}
return dp[n-1];
}
​
};
```