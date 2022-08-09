class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        int initialColor = image[sr][sc];
        
        if(initialColor != newColor)
            dfs(sr, sc, rows, cols, newColor, initialColor, image);
        
        return image;
    }
    
    void dfs(int row, int col, int rows, int cols, int newColor, int initialColor, vector<vector<int>>& image)
    {
        // Boundary Conditions
        if(row < 0 or row >= rows or col < 0 or col >= cols) return;
        
        // If current cell color is not equal to the initial cell color
        if(image[row][col] != initialColor) return;
        
        image[row][col] = newColor;
        
        // Traversal
        dfs(row + 1, col, rows, cols, newColor, initialColor, image);
        dfs(row - 1, col, rows, cols, newColor, initialColor, image);
        dfs(row, col + 1, rows, cols, newColor, initialColor, image);
        dfs(row, col - 1, rows, cols, newColor, initialColor, image);

    }
};