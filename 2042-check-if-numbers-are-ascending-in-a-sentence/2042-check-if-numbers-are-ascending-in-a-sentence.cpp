class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string word;
        int prev = 0;
        while(ss >> word) 
        {
            if(word[0] >= '0' and word[0] <= '9')
            {
                int num = stoi(word);
                if(num <= prev) return false;
                prev = num;
            }
        }
        
        return true;
        
        
    }
};