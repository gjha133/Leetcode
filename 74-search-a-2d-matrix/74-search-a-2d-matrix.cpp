class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int n = A.size(), m = A[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int midval = A[mid/m][mid % m];
            if(target == midval) return true;
            else if(target > midval) start = mid + 1;
            else end = mid - 1;
        }
        
        return false;
        
    }
};