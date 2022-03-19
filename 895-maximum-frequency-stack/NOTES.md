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
​
```
​
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
// Ex.        [1, 2, 3, 1, 1]
// timestamp:  0  1  2  3  4