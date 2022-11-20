class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        
        int ans = 0;
        for(int& answer : answers)
        {
            if(answer == 0) ans++;
            else
            {
                if(mp[answer] == 0) ans += answer + 1;
                mp[answer]++;
                if(mp[answer] == answer + 1) mp[answer] = 0;
            }
        }
        return ans;
    }
};