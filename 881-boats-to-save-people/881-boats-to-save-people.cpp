class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end());
        int lesser = 0;
        int higher = people.size()-1;
        while(lesser <= higher)
        {
            if(people[lesser] + people[higher] <= limit) {lesser++; higher--; count++;}
            else {count++; higher--;}
        }
        
        return count;
    }
};