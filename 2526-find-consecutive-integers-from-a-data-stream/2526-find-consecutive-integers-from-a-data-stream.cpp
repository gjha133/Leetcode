class DataStream {
public:
    int val = 0, mx = 0, count = 0;
    DataStream(int value, int k) {
        val = value;
        mx = k;
    }
    
    bool consec(int num) {
        if(num == val) count++;
        else count = 0;
        
        return count >= mx;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */