class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(isValid(i, j, board, board[i][j]) == false) return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid(int r , int c, vector<vector<char>>& board, char val)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            if(i != c && board[r][i] == val) return false;
            if(i != r && board[i][c] == val) return false;
        }
        
        int y = (r/3)*3;
        int x = (c/3)*3;
        
        for(int i = y ; i < y+3 ; i++){
            for(int j = x ; j < x+3 ; j++){
                if(!(i == r && j == c) && board[i][j] == val ) return false;
            }
        }
        return true;
    }
};