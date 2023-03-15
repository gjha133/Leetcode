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
    bool isCompleteTree(TreeNode* root) {
        bool nullBeforeNode = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(size(q))
        {
            auto node = q.front();
            q.pop();
            
            if(node == NULL) nullBeforeNode = true;
            else 
            {
                if(nullBeforeNode) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};