class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> ans (rows*cols);
        
        int row = 0, col = 0;
        for(int i=0; i<rows*cols; i++)
        {
            ans[i] = mat[row][col];
            // Checking sum of row + col
            if(!((row + col)&1))  // If the sum is even. We will go in upward direction. row-- col++
            {
                // If it is the last column. We cant go up so we will move to next row (3->6)
                if(col == cols-1) row++; 
                // If it is the first row. We will move to next column (1->2)
                else if(row == 0) col++;
                // Simply move diagonally up
                else row--, col++;
            }
            else //If the sum is odd. We will go in downward direction. row++ col--
            {
                // If it is the last row. We cant go down so we will move to next col (8->9)
                if(row == rows-1) col++;
                // If it is the first col. We will move to next row (4->7)
                else if(col == 0) row++;
                // Simply move digonally down
                else row++, col--;
            }
        }
        return ans;
    }
};