// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            bool bad = isBadVersion(mid);
            if(bad == false) start = mid + 1;
            else end = mid - 1;
        }
        
        return start;
    }
};