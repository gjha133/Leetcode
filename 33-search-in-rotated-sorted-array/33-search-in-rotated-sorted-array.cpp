class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = minIndex(nums);
        int left = binSearch(nums, 0, index-1, target);
        int right = binSearch(nums, index, nums.size()-1, target);
        if(left == -1 and right == -1) return -1;
        else if(left != -1 and right == -1) return left;
        else return right;
        
    }
    
    int binSearch(vector<int> &nums, int start, int end, int target)
    {
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(target == nums[mid]) ans = mid;
            if(target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return ans;
    }
    
    int minIndex(vector<int> &nums)
    {
        int ans = INT_MAX;
        int start = 0, end = nums.size()-1, index;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(ans >= nums[mid])
            {
                ans = nums[mid];
                index = mid;
            }
            
            if(nums[mid] > nums[end]) start = mid + 1;
            else end =  mid - 1;
        }
        
        return index;
    }
};