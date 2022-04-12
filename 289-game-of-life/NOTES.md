class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
vector<vector<int>> copy = board;
int n = board[0].size(), m = board.size();
for(int row = 0; row < m; row++)
{
for(int col = 0; col < n; col++)
{
int sum = neighbours(copy, row, col, m, n);
if(board[row][col] == 0 and sum == 3) board[row][col] = 1;
else if(sum < 2 or sum > 3) board[row][col] = 0;
}
}
}
int neighbours(vector<vector<int>>& copy, int row, int col, int m, int n)
{
int live = 0;
// Upper Neighbour
if(row > 0 and copy[row-1][col] == 1) live++;
// Lower Neighbour
if(row < m-1 and copy[row+1][col] == 1) live++;