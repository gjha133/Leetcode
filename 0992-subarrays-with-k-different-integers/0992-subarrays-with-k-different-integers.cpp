class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return atMostKDistinct(nums, n, k) - atMostKDistinct(nums, n, k-1);
    }
    
    
    int atMostKDistinct(vector<int>& nums,int n,int k)
    {
        int count = 0;
        int i = 0;
        int j = 0;

        unordered_map<int,int> mp;

        while(j < n)
        {
            mp[nums[j]]++;        
            while(mp.size() > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};