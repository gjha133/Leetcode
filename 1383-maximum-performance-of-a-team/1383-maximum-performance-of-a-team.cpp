class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> stats(n);
        
        for(int i = 0; i < n; i++)
        {
            stats[i] = {efficiency[i], speed[i]};
        }
        
        sort(stats.rbegin(), stats.rend());
        
        long speedSum = 0, ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& [e, s] : stats)
        {
            pq.push(s);
            speedSum += s;
            
            if(pq.size() > k)
            {
                speedSum -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, speedSum * e);
        }
        
        return ans % mod;
    }
};