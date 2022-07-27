class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        
        int sum = 0;
        int pRow = 0, pCol = 0;
        int sRow = 0, sCol = n-1;
        for(int i=0; i<n; i++)
        {
            sum += mat[pRow++][pCol++];
            sum += mat[sRow++][sCol--];
        }
        
        bool odd = n&1;
        
        return odd ? sum - mat[n/2][n/2] : sum;
    }
};