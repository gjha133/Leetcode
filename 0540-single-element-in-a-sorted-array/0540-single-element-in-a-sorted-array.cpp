class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {;
        if(nums.size() == 1) return nums[0];
        int start = 0, end = nums.size()-1;

        if (nums[0] != nums[1]) return nums[0]; 
        if (nums[end] != nums[end - 1]) return nums[end];
                                               
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] != nums[mid+1] and nums[mid] != nums[mid-1])
                return nums[mid];
            else if(  (nums[mid] == nums[mid+1] and mid % 2 == 0) or (nums[mid] == nums[mid-1] and mid&1) )
                start = mid + 1;
            else
                end = mid - 1;
        }                 
        
        return nums[start];                                      
    }
};