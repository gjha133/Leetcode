var solveSudoku = function(board) {
  const n = board.length;
  dfs(board, n);
}

var dfs = function(board, n) {
  for (let row = 0; row < n; row++) {
    for (let col = 0; col < n; col++) {
      if (board[row][col] !== '.') continue;

      for (let i = 1; i <= 9; i++) {
        const c = i.toString();

        if (isValid(board, row, col, n, c)) {
          board[row][col] = c;
          // continue search for that board, ret true if solution is reached
          if (dfs(board, n)) return true;
        }
      }
      // solution wasnt found for any num 1-9 here, must be a dead end...
      // set the current cell back to empty
      board[row][col] = '.';
      // ret false to signal dead end 
      return false;
    }
  }
  // all cells filled, must be a solution
  return true;
}

var isValid = function(board, row, col, n, c) {
  const blockRow = Math.floor(row / 3) * 3;
  const blockCol = Math.floor(col / 3) * 3;
  for (let i = 0; i < n; i++) {
    if (board[row][i] === c || board[i][col] === c) return false;
    const curRow = blockRow +  Math.floor(i / 3);
    const curCol = blockCol +  Math.floor(i % 3);
    if (board[curRow][curCol] === c) return false;
  }
  return true;
}