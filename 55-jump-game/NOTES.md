## Recursive :
```
bool canJump(vector<int>& nums) {
return f(0, nums);
}
bool f(int i, vector<int>& nums)
{
int n = nums.size();
if(i == n - 1) return true;
if(nums[i] == 0) return false;
for(int j = i + 1; j <= i + nums[i]; j++)
{
if(f(j, nums)) return true;
}
return false;
}
```
​
​
​
## Greedy O(n)
```
bool canJump(vector<int>& nums) {
int n = nums.size();
int reachable = 0;
for(int i = 0; i < n; i++)
{
if(i > reachable) return false;
reachable = max(reachable, i + nums[i]);
}
return true;
}
```