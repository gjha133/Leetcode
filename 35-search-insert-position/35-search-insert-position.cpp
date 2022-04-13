class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else
            {
                start = mid + 1;
                ans = mid;
            }
        }
        return start;
        //return ans == -1 ? 0 : ans + 1;
    }
};