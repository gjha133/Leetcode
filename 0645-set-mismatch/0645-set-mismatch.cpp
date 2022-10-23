class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int initialSum = accumulate(nums.begin(), nums.end(), 0);
        
        set<int> set;
        for(int num : nums) set.insert(num);
        int sum = accumulate(set.begin(), set.end(), 0);
        
        int Sn = n*(n+1)/2;
        
        
        return {initialSum - sum, Sn - sum};
        
        
    }
};