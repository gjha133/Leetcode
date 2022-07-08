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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            bool f1 = false, f2 = false;
            
            for(int i=0; i<n; i++)
            {
                auto node = q.front();
                q.pop();
                
                //if values found
                if(node->val == x) f1 = true;
                if(node->val == y) f2 = true;
                
                auto L = node->left, R = node->right;
                
                //checking if parent is same
                if(L and R)
                {
                    if((L->val == x and R->val == y) or (L->val == y and R->val == x)) return false;
                }
                
                if(L) q.push(L);
                if(R) q.push(R);
            }
          
            if(f1 and f2) return true;
        }
        
        return false;
    }
};