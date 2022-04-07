class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size(), start = 0, end = n-1, mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(citations[mid] == n - mid) return citations[mid];
            else if(citations[mid] > n - mid) end = mid - 1;
            else start = mid + 1;            
        }
        
        return n - start;
    }
};