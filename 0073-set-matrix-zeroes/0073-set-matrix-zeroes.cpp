class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        bool rowZero = false, colZero = false;
        
        // Check in first row
        for(int j = 0; j < m; j++)
        {
            if(arr[0][j] == 0)
            {
                rowZero = true;
                break;
            }
        }
        
        // Check in first col
        for(int i = 0; i < n; i++)
        {
            if(arr[i][0] == 0)
            {
                colZero = true;
                break;
            }
        }
        
        // Except first row and col
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
                    
            }
        }
        
        // Mark as 0 for apt case
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(arr[0][j] == 0 or arr[i][0] == 0)
                    arr[i][j] = 0;
            }
        }
        
        if(rowZero) //handle the first row
        { 
            for (int i = 0; i < m; i++) 
            {
                arr[0][i] = 0;
            }
        }
        if (colZero) //handle the first column
        { 
            for (int i = 0; i < n; i++)
            {
                arr[i][0] = 0;
            }
        }
    }
};