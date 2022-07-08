class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        stringstream ss (preorder);
        string curr;
        int node = 1;
        while(getline(ss, curr, ','))
        {
            if(node <= 0) return false;
            if(curr == "#") node--;
            else node++;
        }
        
        return node == 0;
    }
};