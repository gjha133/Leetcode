class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] > nums[i]) count++;            
        }
        /*
            In case of [2, 1, 3, 4] 
            If array is sorted and rotated, nums[0] > nums[n-1]
        */
        
        if(nums[0] < nums[n-1]) count++;
        
        return count <= 1;
        
    }
};