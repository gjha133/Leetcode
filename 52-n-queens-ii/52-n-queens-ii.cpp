class Solution {
public:
    int totalNQueens(int n) 
    {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        vector<int> leftRow(n,0), upper(2*n-1,0), lower(2*n-1,0);
        return placeQueen(0, board, n, leftRow, upper, lower);
    }
    
    int placeQueen(int col, vector<string> &board, int n, vector<int>& leftRow, vector<int>& upper, vector<int>& lower)
    {
        if(col == n) return 1;
        int l = 0;
        for(int row = 0; row < n; row ++)
        {
            if(leftRow[row] == 0 and lower[row+col] == 0 and upper[n-1 + col - row] == 0)
            {
                leftRow[row] = 1, lower[row+col] = 1, upper[n-1 + col - row] = 1;
                board[row][col] = 'Q';
                l += placeQueen(col + 1, board, n, leftRow, upper, lower);
                board[row][col] = '.';
                leftRow[row] = 0, lower[row+col] = 0, upper[n-1 + col - row] = 0;
            }
        }
        return l;
    }
};



