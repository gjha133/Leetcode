class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> rows(n, 1), cols(m, 1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(rows[i] == 0)
            {
                for(int j = 0; j < m; j++)
                    arr[i][j] = 0;
            }
        }
        
        for(int j = 0; j < m; j++)
        {
            if(cols[j] == 0)
            {
                for(int i = 0; i < n; i++)
                    arr[i][j] = 0;
            }
        }
    }
};