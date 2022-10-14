class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> set;
        int horizontal = 0, vertical = 0;
        
        set.insert({0, 0});
        
        for(char direction : path)
        {
            if(direction == 'N') vertical++;
            else if(direction == 'S') vertical--;
            else if(direction == 'E') horizontal++;
            else horizontal--;
            
            if(set.count({horizontal, vertical}) > 0) return true;  // If we encounter (0,0), return true as we have reached origin
            set.insert({horizontal, vertical});
        }
        
        return false;
    }
};