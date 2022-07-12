class NumMatrix {
public:
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1)); // sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // For a cell in matrix, sum is
                // Sum of [ 1 above + 1 left - 1 diagonal + cell value from matrix]                
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        // For debugging purpose
        /*
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
    int sumRegion(int r1, int c1, int r2, int c2) 
    {
		// Since our `sum` starts by 1 so we need to increase r1, c1, r2, c2 by 1
        r1++; c1++; r2++; c2++; 
        // Sum of whole rectangle - column - row + top left element
        return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    }
};
