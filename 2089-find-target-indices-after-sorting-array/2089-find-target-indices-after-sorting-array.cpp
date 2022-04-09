class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int belowtarget = 0, istarget = 0;
        for(int num : nums)
        {
            if(num == target) istarget++;
            else if(num < target) belowtarget++;
        }
        
        vector<int> ans;
        while(istarget--) ans.push_back(belowtarget++);
        
        return ans;
    }
};