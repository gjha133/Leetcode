Solution 1: HashMap
*  We need to find 2 numbers a, b so that a + b = target.
*  We need a HashMap datastructure to store elements in the past, let name it map.
*  The idea is that we iterate b as each element in nums, we check if we found a (where a = target - b) in the past.
If a exists in map then we already found 2 numbers a and b, so that a + b = target, just output their indices.
Else add b to the map.
​
```
class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int, int> map;
for(int i=0; i<nums.size(); i++)
{
int b = nums[i], a = target - nums[i];
if(map.count(a)) return {map[a], i};
map[b] = i;
}
return {};
}
};
​
```
​
​