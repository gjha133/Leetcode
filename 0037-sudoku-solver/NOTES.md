if(board[ 3*(row/3) + i/3 ][ 3*(col/3) + i%3 ] == c) return false;
}
return true;
}
};
```
​
​
​
​
```
```
/**
* @param {character[][]} board
* @return {void} Do not return anything, modify board in-place instead.
*/
var solveSudoku = function(board) {
const n = board.length;
dfs(board, n);
};
​
var dfs = function(board, n) {
for(let row = 0; row < n; row++) {
for(let col = 0; col < n; col++) {
if(board[row][col] == '.') continue;
for(let c = '1'; c <= '9'; c++) {
if(isValid(board, row, col, n, c)) {
board[row][col] = c;
}
if(dfs(board, n)) return true;
}
board[row][col] = '.';
return false;