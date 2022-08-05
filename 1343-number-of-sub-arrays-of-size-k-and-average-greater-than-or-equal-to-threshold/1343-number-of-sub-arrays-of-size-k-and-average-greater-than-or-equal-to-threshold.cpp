class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0, n = arr.size();
        int mx = k * threshold;
        int sum = 0;
        int ans = 0;
        
        while(j < n)
        {
            sum += arr[j];
            if(j - i + 1 == k) 
            {
                if(sum >= mx) ans++;
                sum -= arr[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};