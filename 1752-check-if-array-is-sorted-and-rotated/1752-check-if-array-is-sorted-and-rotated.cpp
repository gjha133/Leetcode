class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > nums[ (i+1) % n ]) count++;
            if(count == 2) return false;
            
            /*
            In case of [2, 1, 3, 4] 
            If array is sorted and rotated, num[0] > num[4]
            */
        }
        
        return true;
        
    }
};