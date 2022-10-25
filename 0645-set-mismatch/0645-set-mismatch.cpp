class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long Sn = n*(n+1)/2;
        long long SSn = Sn*(2*n+1)/3;
        
        long long X = 0, Y = 0;     // X = missing, Y = repeating
        
        for(int num : nums)
        {
            Sn -= num;
            SSn -= num*num;
        }
        
        X = (Sn + SSn/Sn)/2;
        Y = X - Sn;
        
        return {(int)Y, (int)X};
        
    }
};