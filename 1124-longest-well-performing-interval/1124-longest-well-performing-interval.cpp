class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, well = 0, n = hours.size();
        
        unordered_map<int ,int> mp;
        
        for(int i = 0; i < n; i++)
        {
            hours[i] > 8 ? well++ : well--;
            
            if(well > 0) ans = i + 1;
            else
            {
                if(mp.count(well) == 0) 
                    mp[well] = i;
                if(mp.count(well-1))
                    ans = max(ans, i - mp[well-1]);
            }
        }
        
        return ans;
    }
};