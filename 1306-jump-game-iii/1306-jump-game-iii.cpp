class Solution {
public:
    bool canReach(vector<int>& arr, int i) {
        int n = arr.size();
        
        if(i >= arr.size() or i < 0 or arr[i] < 0) return false;
        
        if(arr[i] == 0) return true;
        
        arr[i] *= -1;
        return canReach(arr, i + arr[i]) or canReach(arr, i - arr[i]);        
    }
    
};