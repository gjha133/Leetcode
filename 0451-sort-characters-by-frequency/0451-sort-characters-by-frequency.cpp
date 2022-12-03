class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;        
        for(char c : s) mp[c]++;
        for(auto it : mp) pq.push({it.second, it.first});
        
        string ans = "";
        while(!pq.empty())
        {
            int freq = pq.top().first;
            char x = pq.top().second;
            pq.pop();
            
            while(freq--) ans += x;            
        }
        
        return ans;
    }
};