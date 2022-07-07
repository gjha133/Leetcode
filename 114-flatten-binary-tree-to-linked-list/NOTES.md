Recursive Solution:
​
```
class Solution {
public:
using N = TreeNode;
void flatten(TreeNode* root) {
N* prev = NULL;
helper(root, prev);
}
void helper(N* root, N* &prev)
{
if(!root) return;
helper(root->right, prev);
helper(root->left, prev);
root->right = prev;
root->left = NULL;
prev = root;
}
};
```
​
​
Iterative Solution :
​
```
​
```
​