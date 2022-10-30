class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mx = 0, i = 1, n = arr.size();
        
        while(i < n) 
        {
            int peak = 0, valley = 0;
            while(i < n && arr[i] > arr[i - 1]) peak++, i++;
            while(i < n && arr[i] < arr[i - 1]) valley++, i++;
            if(peak > 0 && valley > 0) mx = max(mx, peak + valley + 1);
            else if(!peak && !valley) i++;
        }
        
        return mx;
    }
};