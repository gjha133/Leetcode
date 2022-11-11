class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto& c : nums) 
            while(nums[c-1] != c) 
				swap(c, nums[c-1]);               // swap till correct index place of c is not occupied by c itself
        for(int i = 1; i <= size(nums); i++)
            if(i != nums[i-1]) ans.push_back(nums[i-1]);  // correct index place of i is not occupied by i itself
        return ans;

    }
};