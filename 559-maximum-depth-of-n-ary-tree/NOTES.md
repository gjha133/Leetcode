Recursive DFS:
​
```
class Solution {
public:
int maxDepth(Node* root) {
if (root == nullptr) return 0;
int depth = 0;
for (auto child : root->children) depth = max(depth, maxDepth(child));
return 1 + depth;
}
};
```
​
BFS:
```
class Solution {
public:
int maxDepth(Node* root) {
if (root == nullptr) return 0;
queue<Node*> q; q.push(root);
int depth = 0;
while (!q.empty()) {
depth += 1;
int breadth = q.size();
for (int _ = 0; _ < breadth; ++_) {
auto node = q.front(); q.pop();
for (auto child : node->children) if (child) q.push(child);
}
}
return depth;
}
};
```
​