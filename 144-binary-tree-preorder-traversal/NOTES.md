Iterative
​
```
vector < int > preOrderTrav(node * curr) {
vector < int > preOrder;
if (curr == NULL)
return preOrder;
​
stack < node * > s;
s.push(curr);
​
while (!s.empty()) {
node * topNode = s.top();
preOrder.push_back(topNode -> data);
s.pop();
if (topNode -> right != NULL)
s.push(topNode -> right);
if (topNode -> left != NULL)
s.push(topNode -> left);
}
return preOrder;
​
}
​
```
​
Recursive
​
```
class Solution {
public:
vector<int> preorderTraversal(TreeNode* root) {
vector<int> preOrder;
preorder(root, preOrder);
return preOrder;
}
private:
void preorder(TreeNode* root, vector<int> &preOrder)
{
if(!root) return;
preOrder.push_back(root->val);
preorder(root->left, preOrder);
preorder(root->right, preOrder);
}
};
```