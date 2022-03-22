class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = n-1;
        int k = m+n-1;    // calculate the index of the last element of the merged array
        
        // go from the back by A and B and compare and put to the A element which is larger
        while(i >= 0 and j >= 0){
            if(nums1[i] > nums2[j])     nums1[k--] = nums1[i--];
            else                        nums1[k--] = nums2[j--];
        }
        
        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(j >= 0)         nums1[k--] = nums2[j--];
    }
};