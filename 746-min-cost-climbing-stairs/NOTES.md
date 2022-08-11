Memoization:
```
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
vector<int> dp(cost.size() + 1, -1);
return min(f(0, cost, dp), f(1, cost, dp));
}
int f(int ind, vector<int> &cost, vector<int> &dp)
{
// If we go out of bound, we have reached the top of the floor
if(ind >= cost.size()) return 0;
if(dp[ind] != -1) return dp[ind];
int oneStep = f(ind + 1, cost, dp) + cost[ind];
int twoStep = f(ind + 2, cost, dp) + cost[ind];
return dp[ind] = min(oneStep, twoStep);
}
};
```
​
Tabulation:
​
Variable:
```
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
int n = cost.size();
int prev2 = cost[0], prev1 = cost[1];
for(int i = 2; i<n; i++)
{
int curr = cost[i] + min(prev1, prev2);
prev2 = prev1;
prev1 = curr;
}
return min(prev1, prev2);
}
};
```
​
​
​