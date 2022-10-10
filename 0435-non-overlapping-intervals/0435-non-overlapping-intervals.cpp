// Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int count = 0, i = 0, j = 1, n = intervals.size();
        
        while(j < n)
        {
            if(intervals[i][1] <= intervals[j][0])          i = j;              // Case 1
            else if(intervals[i][1] <= intervals[j][1])     count++;            // Case 2
            else if(intervals[i][1] > intervals[j][1])
            {
                count++;                                                        // Case 3
                i = j;
            }
            j++;
        }
        
        return count;
    }
};