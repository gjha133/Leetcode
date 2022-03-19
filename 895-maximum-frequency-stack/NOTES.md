```
class FreqStack {
    priority_queue<pair<int, pair<int, int>>> q;
    unordered_map<int, int> freq;
    int pos = 0;
public:
    void push(int x) {
        q.emplace(++freq[x], make_pair(++pos, x));
    }
    
    int pop() {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

```

self-explained code:
```
using Freq = int;
using Timestamp = int;
class FreqStack {
public:
    // max pq
    priority_queue<tuple<Freq, Timestamp, int>> pq;
    unordered_map<int, Freq> map;
    int timestamp;
    FreqStack() {
        timestamp = 0;
    }
    
    void push(int val) {
        int f = ++map[val];
        // Explanation:
        // Ex.        [1, 2, 3, 1, 1]
        // timestamp:  0  1  2  3  4 
        // freq        1  1  1  2  3
        
        // Frequency is placed as the first
        // because we want to pop the most frequent one
        // And the timestamp is also important because we want the most recent
        // one on the top
        // And val basically means nothing,
        // because of the timestamps are unique, we won't use it
        // to compare
        pq.push({f, timestamp++, val});
    }
    
    int pop() {
        int f, tidx, val;
        tie(f, tidx, val) = pq.top();
        pq.pop();
        map[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

```
same idea but used tuple instead of pairs:
```
class FreqStack {
public:
    void push(int val) {
        freqStack.emplace(++counts[val], prio++, val);
    }
    
    int pop() {
        const auto [f, p, v] = freqStack.top();
        freqStack.pop();
        --counts[v];
        return v;
    }
private:
    int prio {0};
    unordered_map<int, int> counts;
    priority_queue<tuple<int, int, int>> freqStack;
};

```

