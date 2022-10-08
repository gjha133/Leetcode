class CustomStack {
public:
    
    int max;
    vector<int> stack;
    
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < max)
            stack.push_back(x);
    }
    
    int pop() {
        if(stack.size() == 0) return -1;
        int x = stack.back();
        stack.pop_back();
        return x;
    }
    
    int min(int x, int y)
    {
        return x < y ? x : y;
    }
    
    void increment(int k, int val) {
        k = min(stack.size(), k);
        for(int i = 0; i < k; i++) stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */