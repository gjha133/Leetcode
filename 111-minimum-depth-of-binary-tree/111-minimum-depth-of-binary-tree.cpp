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
    int minDepth(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(!root) return 0; 
        q.push(root);
        int minDepth = 1;
        
        while(q.size()) 
        {
            int n = q.size();
            while(n--) 
            {
                TreeNode* cur = q.front();
                q.pop();

                if(!cur->left && !cur->right) return minDepth;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ++minDepth;
        }
        
        return minDepth;
    }
};