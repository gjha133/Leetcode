class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0, product = 1;
        
        for(int num : nums)
        {
            if(num < 0) ++count;
            else if(!num) return 0;    // num == 0
        }
        
        return count&1 == 1 ? -1 : 1;
    }
};