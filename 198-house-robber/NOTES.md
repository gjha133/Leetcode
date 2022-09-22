Recursion Brute Force:
```
class Solution {
public:
int rob(vector<int>& nums) {
int n = nums.size();
return robber(0, n, nums);
}
private:
int robber(int i, int n, vector<int> &nums)
{
if(i >= n) return 0;
if(i == n-1) return nums[i];
int pick = nums[i] + robber(i+2, n, nums);
int notpick = robber(i+1, n, nums);
return max(pick, notpick);
}
};
```
​
Memoization:
```
class Solution {