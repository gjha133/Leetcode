class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start = 0, end = nums.size() - 1, pos = nums.size() - 1;
        while(start <= end and pos >=0)
        {
            if(abs(nums[start]) > abs(nums[end])) ans[pos--] = nums[start]*nums[start++];
            else ans[pos--] = nums[end]*nums[end--];
        }
        return ans;
               
        
              
        
        /* Trivial solution.
        //Squaring the numbers then sorting them.
        //Time complexity will be O(n) + O(nlogn)
        for(int i=0; i<nums.size(); i++) nums[i] = nums[i]*nums[i];
        sort(nums.begin(), nums.end());
        return nums;
        */
    };
};