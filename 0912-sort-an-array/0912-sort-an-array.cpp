class Solution {
public:    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        // Bubble Sort
        // for(int i = 0; i < n-1; i++){
        //     for(int j = 1; j < n; j++){
        //         if(nums[j-1] > nums[j])
        //             swap(nums[j], nums[j-1]);
        //     }
        // }
        
        // Selection Sort
        // for(int i = 0; i < n-1; i++) {
        //     int mn = i;
        //     for(int j = i+1; j < n; j++) {
        //         if(nums[j] < nums[mn])
        //             mn = j;
        //     }
        //     swap(nums[mn], nums[i]);
        // }
        
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
    
    
    
    
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l; // cursor for final pivot location 
        for(int j = l; j <= r - 1; j++){ // nums[r] is chosen as the pivot
            if(nums[j] <= nums[r]){
                swap(nums[i], nums[j]);
                i++; // smaller or equal elements go to the left of i 
            }
        }
        swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
};