}
void placeQueen(int col, vector<string> &board, vector<vector<string>> &ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n)
{
if(col == n)
{
ans.push_back(board);
return;
}
for(int row = 0; row < n; row++)
{
if(leftRow[row] == 0 and lowerDiagonal[row+col] == 0 and upperDiagonal[n-1 + col - row] == 0)
{
board[row][col] = 'Q';
leftRow[row] = 1; lowerDiagonal[row+col] = 1, upperDiagonal[n-1 + col - row] = 1;
placeQueen(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
board[row][col] = '.';
leftRow[row] = 0; lowerDiagonal[row+col] = 0, upperDiagonal[n-1 + col - row] = 0;
}
}
}
};
​
```