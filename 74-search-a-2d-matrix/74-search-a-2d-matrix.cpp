class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        
        int row = A.size(), col = A[0].size();
        int i = 0, j = col - 1;
        
        while(i < row and j >= 0)
        {
            if(A[i][j] == target) return true;
            else if(A[i][j] > target) j--;
            else i++;
        }
        
        return false;
    }
};