class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        
        placeQueen(0, board, ans, n);
        return ans;        
    }
    
    void placeQueen(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                placeQueen(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // Only need to check for 3 directions.
        // As we place the queen we need to check past places. So we check for above, upper left and lower left.
        
        // Check upper left diagonal
        int r = row, c = col;
        
        while(row >= 0 and col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }
        
        // Check above
        row = r, col = c;
        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        // Check lower left diagonal
        row = r, col = c;
        while(row  < n and col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row++; col--;
        }
        
        return true;
    }
    
    
};