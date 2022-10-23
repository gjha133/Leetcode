class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[n - 1];
        arr[n-1] = -1;
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] >= mx)
            {
                int newmx = arr[i];
                arr[i] = mx;
                mx = newmx;
            }
            else arr[i] = mx;
        }
        
        return arr;
    }
};