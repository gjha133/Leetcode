class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), mn = INT_MAX;
        unordered_map<int, int> mp;     // Store Card Value and its index
        
        for(int i = 0; i < n; i++)
        {
            // If found in map
            if(mp.count(cards[i]))
            {
                // Find size of window from prev index to current index
                int prev = mp[cards[i]];
                mn = min(mn, i - prev + 1);
            }
            // If not found in map, insert it
            mp[cards[i]] = i;
        }
        
        return mn == INT_MAX ? -1 : mn;
    }
};