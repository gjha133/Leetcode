class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int& task : tasks) mp[task]++;
        
        int num, freq, ans = 0;
        
        for(auto [num, freq] : mp)
        {
            if(freq == 1) return -1;
            if(freq % 3 == 0) ans += freq/3;
            else
            {
                ans += freq/3 + 1;
            }
        }
        
        return ans;
    }
};