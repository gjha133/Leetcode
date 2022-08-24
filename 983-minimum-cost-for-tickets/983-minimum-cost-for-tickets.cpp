class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp (n + 1, 0);
        
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
            int day_pass = costs[0] + dp[i+1];
            
            int d;
            for(d = i ; d < n and days[d] < days[i] + 7; d++);
            int week_pass = costs[1] + dp[d];

            for(d = i ; d < n and days[d] < days[i] + 30; d++);
            int month_pass = costs[2] + dp[d];
            
            dp[i] = min(day_pass, min(week_pass, month_pass));
        }
        
        return dp[0];
    }
};