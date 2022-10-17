class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq (26);
        for(char c : sentence) freq[c-'a']++;
        
        for(int count : freq) if(count < 1) return false;
        return true;
    }
};