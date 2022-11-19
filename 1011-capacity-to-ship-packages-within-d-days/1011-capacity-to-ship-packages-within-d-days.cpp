class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), mx = 0, sum = 0;
        
        for(int& weight : weights)
        {
            mx = max(mx, weight);
            sum += weight;
        }
        
        int start = mx, end = sum, ans = 0;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(isPossible(weights, days, mid))
            {
                ans = mid;
                end = --mid;
            }
            else
                start = ++mid;
        }
        
        return ans;
    }
    
    bool isPossible(vector<int>& weights, int days, int mid)
    {
        int count = 1, sum = 0;
        
        for(int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if(sum > mid)
            {
                count++;
                sum = weights[i];
            }
        }
        
        if(count <= days) return true;
        return false;
    }
};