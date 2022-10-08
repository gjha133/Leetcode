/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   int maxDepth = 0, sum = 0;
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        dfs(root, depth);
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int depth)
    {
        if(!root) return;
        
        if(!root->left and !root->right)
        {
            if(depth > maxDepth)
            {
                sum = root->val;
                maxDepth = depth;
            }
            else if(depth == maxDepth) sum += root->val;
        }
        
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};