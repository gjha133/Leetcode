class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Store value of matrix size
        int n = matrix.size();
        
        int start = matrix[0][0];   // First element
        int end = matrix[n-1][n-1]; // Last element
        
        int mid, temp, count;
        
        while(start < end){
            mid = start + (end-start)/2;
            temp = n - 1;
            count = 0;
            
            // For each row count the elements that are smaller than mid
            for(int i = 0; i < n; i++)
            {
                while(temp >= 0 && matrix[i][temp] > mid) temp--;
                
                count+= (temp+1);
            }
            cout << "start :" << start << "   end :" << end << "    count :" << count << endl;
            
            if(count < k) start = mid + 1;
            else end = mid;
        }
        
        return start;
    }
};