class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = -1, ans = 0;
        for(int i = 0; i < size(arr); i++)
        {
            mx = max(mx, arr[i]);
            if(mx == i) ans++;
        }
        
        return ans;
    }
};