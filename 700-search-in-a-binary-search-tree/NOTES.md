#### Recursive
```
TreeNode* searchBST(TreeNode* root, int val) {
if(!root) return nullptr;
if(root->val == val) return root;
else if(val < root->val) return searchBST(root->left, val);
else return searchBST(root->right, val);
}
};
​
```
#### Iterative
```
TreeNode* searchBST(TreeNode* root, int val) {
while(root && val != root -> val)
root = val < root -> val ? root -> left : root -> right;
return root;
}
​
```