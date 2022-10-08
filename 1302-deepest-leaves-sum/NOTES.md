**2 - pass**
```
class Solution {
public:
int get_depth(TreeNode* root){
if(!root) return 0;
return 1 + max(get_depth(root->left), get_depth(root->right));
}
int get_sum(TreeNode* root, int depth){
if (!root) return 0;
if (depth == 1) return root->val;
return get_sum(root->left, depth-1) + get_sum(root->right, depth-1);
}
int deepestLeavesSum(TreeNode* root) {
int depth = get_depth(root);
int sum = get_sum(root, depth);
return sum;
}
};
```