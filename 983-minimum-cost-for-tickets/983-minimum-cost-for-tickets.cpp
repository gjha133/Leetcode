class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp (n + 1, -1);
        return f(0, days, costs, dp);
    }
    
    int f(int i, vector<int>& days, vector<int>& costs, vector<int>& dp)
    {
        int n = days.size();
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
                
        int day_pass = costs[0] + f(i + 1, days, costs, dp);
        
        int d;
        for(d = i ; d < n and days[d] < days[i] + 7; d++);
        int week_pass = costs[1] + f(d, days, costs, dp);
        
        for(d = i ; d < n and days[d] < days[i] + 30; d++);
        int month_pass = costs[2] + f(d, days, costs, dp);
        
        return dp[i] = min(day_pass, min(week_pass, month_pass));
    }
};