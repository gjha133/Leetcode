class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        // for(int bill : bills) {
        //     if(bill == 5) five++;
        //     else if(bill == 10) five--, ten++;
        //     else if(ten > 0) ten--, five--;
        //     else five -= 3;
        //     if(five < 0) return false;
        // }
        
        for(int bill : bills) {
            switch(bill) {
                case 5:
                    five++;
                    break;
                case 10:
                    five--, ten++;
                    break;
                case 20:
                    ten > 0 ? ten--, five-- : five -= 3;
                    break;
            }
            if(five < 0) return false;
        }
        
        return true;
    }
};