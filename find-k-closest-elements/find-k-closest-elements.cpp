class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), R = ceil(arr, x), L = R-1;
        while(k--)
        {
            if(R >= n or L >= 0 and x - arr[L] <= arr[R] - x) L--;
            else R++;
        }
        
        return vector<int> (begin(arr) + L + 1, begin(arr) + R);
    }
    
    int ceil(vector<int>& arr, int x)
    {
        int start = 0, end = arr.size()-1, mid;
        while(start + 1 < end)
        {
            mid = start + (end-start)/2;
            if(arr[mid] == x) return mid;
            else if(arr[mid] < x) start = mid;
            else end = mid;
        }
        
        return end;
    }
};