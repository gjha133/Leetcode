class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int n = horizontalCuts.size(),m = verticalCuts.size();
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        auto maxVerticalDis = INT_MIN, maxHorizontalDis=INT_MIN;
        
        for(int i=0;i<n;++i){
            if(i==0)
                //Assigning max vertical distance to distance from 0 to first horizontal cut
                maxVerticalDis = max(maxVerticalDis,horizontalCuts[i]); 
            
            else
                maxVerticalDis = max(maxVerticalDis,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        // Checking if the distance between the last horizontal cut and h is greater than the cut in between
        maxVerticalDis = max(maxVerticalDis,h-horizontalCuts[n-1]);
        
        for(int i=0;i<m;++i){
            if(i==0)
                //Assigning max horizontal distance to distance from 0 to first vertical cut
                maxHorizontalDis = max(maxHorizontalDis,verticalCuts[i]);
            else
                maxHorizontalDis = max(maxHorizontalDis,verticalCuts[i] - verticalCuts[i-1]);
        }
        
        // Checking if the distance between the last vertical cut and w is greater than the cut in between
        maxHorizontalDis = max(maxHorizontalDis,w-verticalCuts[m-1]);
        
        return (long) maxHorizontalDis*maxVerticalDis % 1000000007;
    }
};