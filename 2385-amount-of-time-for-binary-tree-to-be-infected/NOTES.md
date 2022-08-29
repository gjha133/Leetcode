private:
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
{
if(!root) return;
if(root->left) parent[root->left] = root;
if(root->right) parent[root->right] = root;
markParents(root->left, parent);
markParents(root->right, parent);
}
TreeNode* findNode(TreeNode* root, int start)
{
if(root)
{
if(root->val == start) return root;
else
{
TreeNode* node = findNode(root->left, start);
if(!node) findNode(root->left, start);
return node;
}
}
else return NULL;
}
};
```