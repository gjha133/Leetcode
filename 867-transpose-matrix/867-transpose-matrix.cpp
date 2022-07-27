class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> A) {
        int r = A.size(), c = A[0].size();
        vector<vector<int>> B(c, vector<int>(r, 0));
        for (int j = 0; j < c; j++)
            for (int i = 0; i < r; i++)
                B[j][i] = A[i][j];
        
        return B;
    }
};