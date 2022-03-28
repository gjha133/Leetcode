class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = INT_MAX;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(ans >= nums[mid]) ans = nums[mid];
            if(nums[mid] > nums[end]) start = mid + 1;
            else end = mid - 1;
        }
        return ans;
    }
    
    
};