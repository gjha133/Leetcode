/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int n = a.length();
        int start, end, peak, mid;
        // find peak index of mountain array
        start = 1, end = n-2;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(a.get(mid) > a.get(mid-1) and a.get(mid) > a.get(mid+1)) {peak = mid; break;}
            else if(a.get(mid-1) > a.get(mid)) end = mid-1;
            else start = mid+1;
        }
        
        
        // find target in the left of peak
        start = 0;
        end = peak;
        while (start <= end) {
            mid = (start + end) / 2;
            if (a.get(mid) < target)start = mid + 1;
            else if (a.get(mid) > target) end = mid - 1;
            else return mid;
        }
        // find target in the right of peak
        start = peak+1;
        end = n - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (a.get(mid) > target) start = mid + 1;
            else if (a.get(mid) < target) end = mid - 1;
            else return mid;
        }
        
        return -1;
    }
    

};