class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;        
        int k = 4;
        while(k--)
        {
            rotate90(mat);
            if(mat == target) return true;
        }
        
        return false;
    }
    
    void rotate90(vector<vector<int>> &m)
    {
        for(int i=0; i<m.size(); i++)
        {
            for(int j=i+1; j<m.size(); j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }
        
        for(int i=0; i<m.size(); i++)
        {
            reverse(m[i].begin(), m[i].end());
        }
    }
};