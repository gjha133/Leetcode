Recursive Brute Force :
```
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
return min(f(0, cost), f(1,cost));
}
int f(int ind, vector<int> &cost)
{
// If we go out of bound, we have reached the top of the floor
if(ind >= cost.size()) return 0;
int oneStep = f(ind + 1, cost) + cost[ind];
int twoStep = f(ind + 2, cost) + cost[ind];
return min(oneStep, twoStep);
}
};
```
​
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
​
​