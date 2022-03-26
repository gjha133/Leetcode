### Binary Search:
​
```
int search(vector<int>& nums, int target) {
int start = 0;
int end = nums.size() - 1;
while(start <= end)
{
int mid = start + (end-start)/2;
if(nums[mid] == target) return mid;
else if(nums[mid] > target) end = mid - 1;
else start = mid + 1;
}
return -1;
}
​
```
Time Complexity is O(log n) &
Space Complexity is O(n).
​
In mid, we used ***start + (end - start)/2*** to avoid overflow in case of very large numbers.
Suppose ***end value is very big*** and you are adding start which will further increase the value so in order to avoid that we first do ***end-start*** then divide by 2 this will decrease the value.
​
​
​
​
​