}
​
```
​
**If you are asked to print out this will not work as we are not travelling in zig zag manner. So to travel in zig-zag manner we will have to use 2 stacks.**
​
```
using N = TreeNode;
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
vector<vector<int>> traversal;
if(!root) return traversal;
stack<N*> s1;
stack<N*> s2;
s1.push(root);
while(!s1.empty() or !s2.empty())
{
vector<int> l2r;
while(!s1.empty())
{
auto top = s1.top();    s1.pop();
l2r.push_back(top->val);
if(top->left) s2.push(top->left);
if(top->right) s2.push(top->right);
}
if(l2r.size() > 0)traversal.push_back(l2r);
vector<int> r2l;
while(!s2.empty())
{
auto top = s2.top();    s2.pop();
r2l.push_back(top->val);
if(top->right) s1.push(top->right);
if(top->left) s1.push(top->left);
}
if(r2l.size() > 0)traversal.push_back(r2l);
}
return traversal;
}
​
```
​
​
​
​