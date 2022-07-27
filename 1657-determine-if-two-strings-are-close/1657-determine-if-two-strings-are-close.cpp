class Solution {
public:
    bool closeStrings(string word1, string word2) {
               
        /*
        if( word1.length() != word2.length() ) return false;
        
        set<char> s1, s2;
        vector<int> w1(26,0), w2(26,0);
        
        for(int i=0; i<word1.length(); i++){
            w1[word1[i]-'a']++;
            s1.insert(word1[i]);
            
            w2[word2[i]-'a']++;            
            s2.insert(word2[i]);
        } 
        
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        
        return s1 == s2 and w1 == w2;     
        */
        
        vector<int> freq1(26,0), freq2(26,0), vis1(26,0), vis2(26,0);
        
        for(char c : word1)
        {
            // For frequency 
            freq1[c-'a']++;
            // Marking visited char as 1
            vis1[c-'a'] = 1;
        }
            
    
        for(char c : word2)
        {
            // For frequency 
            freq2[c-'a']++;
            // Marking visited char as 1
            vis2[c-'a'] = 1;
        }           
            
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));
        
        return freq1 == freq2 and vis1 == vis2;
    }
};