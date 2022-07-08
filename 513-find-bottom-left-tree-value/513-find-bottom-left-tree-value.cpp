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
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int depth = height(root);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n;i++)
            {
                auto p = q.front();
                q.pop();
                auto node = p.first;
                int level = p.second;
                if(i == 0 and depth == level) return ans = node->val;
                if(node->left) q.push({node->left, level + 1});
                if(node->right) q.push({node->right, level + 1});                
            }
        }
        
        return ans;
        
    }
    
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};