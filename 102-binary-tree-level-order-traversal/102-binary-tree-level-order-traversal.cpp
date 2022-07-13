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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> level;
    if(root != NULL){
        
        q.push(root);
        level.push_back(root->val);
        res.push_back(level);
        level.clear();
        
        while(!q.empty()){
            int i, n;
            for(i = 0, n = q.size(); i < n; i++){
                TreeNode* p = q.front();
                q.pop();
                
                if(p -> left != NULL){
                    q.push(p->left);
                    level.push_back(p->left->val);
                }
                if(p-> right != NULL){
                    q.push(p->right);
                    level.push_back(p->right->val);
                }
            }
                if(!level.empty() && i == n){
                    res.push_back(level);
                    level.clear();
                }
        }
    }
     return res;
        
        /*vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        vector<int> output;
        output.push_back(root->val);
        ans.push_back(output);
        if(root->left == NULL && root->right == NULL) return ans;
        
        while(!queue.empty())
        {
            TreeNode* front = queue.front();
            queue.pop();
            
            vector<int> child;
            
            if(front->left)
            {
                queue.push(front->left);
                child.push_back(front->left->val);
            }
            
            if(front->right)
            {
                queue.push(front->right);
                child.push_back(front->right->val);
            }
            
            if(front->left  && front->right) ans.push_back(child);
            
        }
        
        return ans;
        */
    }
};

