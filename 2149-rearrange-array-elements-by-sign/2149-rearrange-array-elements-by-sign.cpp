class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans (nums.size(), 0);
        int pos = 0, neg = 1;
        
        for(auto num : nums)
        {
            if(num > 0) ans[pos] = num, pos +=2;
            else ans[neg] = num, neg+=2;
        }
        
        return ans;
    }
};