## Recursion :
```
class Solution {
public:
int combinationSum4(vector<int>& nums, int target) {
return combinations(nums, target);
}
int combinations(vector<int> &nums, int target)
{
if(target == 0) return 1;
int count = 0;
for(int num : nums)
{
if(target >= num)
count += combinations(nums, target - num);
}
return count;
}
};
```
​
## Memoization :
```
class Solution {
public:
int combinationSum4(vector<int>& nums, int target) {
vector<int> dp (target + 1, -1);
return combinations(nums, target, dp);
}
int combinations(vector<int> &nums, int target, vector<int>& dp)
{
if(target == 0) return 1;
if(dp[target] != -1) return dp[target];
int count = 0;
for(int num : nums)
{
if(target >= num)
count += combinations(nums, target - num, dp);
}
return dp[target] = count;
}
};
```