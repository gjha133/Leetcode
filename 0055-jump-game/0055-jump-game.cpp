class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;

        for(int i = 0; i < n; i++)
        {
            if(reachable == n-1) return true;
            if(i > reachable) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
    
};