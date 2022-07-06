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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans(h);
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);                
            }
            
            ans[h-1] = level;    
            h--;
        }
        
        
        return ans;
    }
    
private:
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};