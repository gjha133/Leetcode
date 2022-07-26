class MyQueue {
public:
    
    stack<int> st, q;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x); 
    }
    
    int pop() {
        if(q.empty())
        {
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
        }
        
        int top = q.top();
        q.pop();
        return top;
    }
    
    int peek() {
        if(q.empty())
        {
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
        }
        
        return q.top();
    }
    
    bool empty() {
        return st.size() == 0 ? q.size() == 0 : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */