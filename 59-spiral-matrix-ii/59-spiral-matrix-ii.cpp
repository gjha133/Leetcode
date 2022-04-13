class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n, vector<int> (n));
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, left = 0, bottom = rows-1, right = cols-1, val = 0;
        while(top <= bottom and left <= right)
        {
            for(int i=left; i<=right; i++)
                matrix[top][i] = ++val;
            top++;
            
            for(int i=top; i<=bottom; i++)
                matrix[i][right] = ++val;
            right--;
            
            for(int i=right; i>=left; i--)
                    matrix[bottom][i] = ++val;
                bottom--;
            
            for(int i=bottom; i>=top; i--)
                    matrix[i][left] = ++val;
                left++;
        }
        
        return matrix;
    }
};