class Solution {
public:
    int numSquares(int n) {            
        
        vector<int> count (n+1, -1);
        count[0] = 0;
        count[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        count[i] = i;
        for(int j=1; i-j*j >=0; j++)
        {
            count[i] = min(count[i], 1 + count[i-j*j]);
        }
    }
    
    return count[n];
        
    }
    
    
    


};