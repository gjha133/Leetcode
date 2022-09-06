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
## Memoization:
```
​
```
​