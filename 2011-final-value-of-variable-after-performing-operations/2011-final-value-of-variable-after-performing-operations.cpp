class Solution {
public:
    
    
    int finalValueAfterOperations(vector<string>& operations) {
		int res = 0;
		for(int i = 0; i < operations.size(); i++){
			(operations[i][1] == '+') ? res++ : res--;
		}
		return res;
	}
};