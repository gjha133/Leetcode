class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        int ans = 0;
        long long sum1 = 0, sum2 = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum1 += arr[i];
            sum2 += sorted[i];
            if(sum1 == sum2) ans++;
        }
        
        return ans;        
    }
};