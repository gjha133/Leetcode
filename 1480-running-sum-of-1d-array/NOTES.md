My Solution that i came up with :
```
class Solution {
public:
vector<int> runningSum(vector<int>& nums) {
int sum = 0;
vector<int> ans (nums.size());
for(int i=0; i<nums.size(); i++)
{
sum += nums[i];
ans[i] = sum;
}
return ans;
}
};
​
```
​
​
​
Solution better :
```
class Solution {
public:
// you can remove the '&' in case you don't want to update the nums array
vector<int> runningSum(vector<int>& nums) {
for(int i=1;i<nums.size();i++) nums[i]+=nums[i-1]; //prefix sum calculation
return nums;
}
};
```