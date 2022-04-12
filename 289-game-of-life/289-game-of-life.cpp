class Solution {
public:
    int neighbours(vector<vector<int>>& copy, int row, int col, int m, int n) 
    {
	    int live = 0;
	    
        // Upper Neighbour
        if(row > 0 and copy[row-1][col] == 1) live++;
        
        // Lower Neighbour
	    if(row < m-1 and copy[row+1][col] == 1) live++;
        
        // Left Neighbour
	    if(col > 0 and copy[row][col-1] == 1) live++;
        
	    // Right Neighbour
	    if(col < n-1 and copy[row][col+1] == 1) live++;
        
        //Upper Left Diagonal live
	    if(row > 0 and col > 0 and copy[row-1][col-1] == 1) live++;
        
	    //Upper Right Diagonal Neighbour
	    if(row > 0 and col < n-1 and copy[row-1][col+1] == 1) live++;
        
	    //Lower Left Diagonal Neighbour 
	    if(row < m-1 and col > 0 and  copy[row+1][col-1] == 1) live++;
        
	    //Lower Right Diagonal Neighbour
	    if(row < m-1 and col < n-1 and copy[row+1][col+1] == 1) live++;
        	    
        return live;
}
    
void gameOfLife(vector<vector<int>>& board) 
{
	vector<vector<int>> copy = board;
	int m = board.size(), n = board[0].size();
	
    for(int row = 0; row < m; row++) 
    {
        for(int col = 0; col < n; col++) 
        {
            int ln = neighbours(copy, row, col, m, n);
                
            if(board[row][col] == 0 and ln == 3) board[row][col] = 1;
            else if(ln < 2 or ln > 3) board[row][col] = 0;
        }		
    }
}
};