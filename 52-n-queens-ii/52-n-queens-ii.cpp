class Solution {
public:
    int totalNQueens(int n) 
    {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;

        return placeQueen(0, board, n);
    }
    
    int placeQueen(int col, vector<string> &board, int n)
    {
        if(col == n) return 1;
        int l = 0;
        for(int row = 0; row < n; row ++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                l += placeQueen(col + 1, board, n);
                board[row][col] = '.';
            }
        }
        return l;
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



