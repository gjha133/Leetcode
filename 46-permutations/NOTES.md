Solution:
​
1st Method........Uses extra space for freq array
​
```
class Solution {
public:
vector<vector<int>> permute(vector<int>& nums) {
vector<vector<int>> ans;
vector<int> ds;
int freq[nums.size()];
for(int i=0; i<nums.size(); i++) freq[i] = 0;
permutation(nums, ans, ds, freq);
return ans;
}
void permutation(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int freq[])
{
if(ds.size() == nums.size())
{
ans.push_back(ds);
return;
}
for(int i=0; i<nums.size(); i++)
{
if(freq[i] == 0)
{
ds.push_back(nums[i]);
freq[i] = 1;
permutation(nums, ans, ds, freq);