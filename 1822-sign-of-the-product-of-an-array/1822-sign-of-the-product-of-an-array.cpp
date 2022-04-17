class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0, product = 1;
        
        for(int num : nums)
        {
            if(num == 0) return 0;
            if(num < 0) ++count;
        }
        
        return count&1 == 1 ? -1 : 1;
    }
};