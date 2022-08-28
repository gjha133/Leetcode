class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], mx = 0;   
        
        for(int i = 1; i < prices.size(); i++)
        {
            int cost = prices[i] - mn;
            mx = max(mx, cost);
            mn = min(mn, prices[i]);
        }
        
        return mx;
    }
};