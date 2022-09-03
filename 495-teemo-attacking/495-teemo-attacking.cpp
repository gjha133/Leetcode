class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int time = 0;
        for(int i = 0; i < n-1; i++)
        {
            int diff = timeSeries[i+1] - timeSeries[i];
            if(diff < duration) time += diff;
            else time += duration;
        }
        
        // Adding duration for the last attack
        return time + duration;
    }
};