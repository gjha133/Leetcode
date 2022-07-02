class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int n = horizontalCuts.size(),m = verticalCuts.size();
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        auto maxVerticalDis = INT_MIN, maxHorizontalDis=INT_MIN;
        
        for(int i=0;i<n;++i){
            if(i==0)
                maxVerticalDis = max(maxVerticalDis,horizontalCuts[i]);
            else
                maxVerticalDis = max(maxVerticalDis,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        maxVerticalDis = max(maxVerticalDis,h-horizontalCuts[n-1]);
        
        for(int i=0;i<m;++i){
            if(i==0)
                maxHorizontalDis = max(maxHorizontalDis,verticalCuts[i]);
            else
                maxHorizontalDis = max(maxHorizontalDis,verticalCuts[i] - verticalCuts[i-1]);
        }
        
        maxHorizontalDis = max(maxHorizontalDis,w-verticalCuts[m-1]);
        
        return (long) maxHorizontalDis*maxVerticalDis % 1000000007;
    }
};