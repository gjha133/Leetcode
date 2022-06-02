class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0, cur_altitude = 0;
        for(int i=0; i<gain.size(); i++)
        {
            cur_altitude += gain[i];
            max_altitude = max(max_altitude, cur_altitude);
        }
        
        return max_altitude;
    }
};