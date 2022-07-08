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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val == key)  return reorganize(root);
        TreeNode* head = root;
        
        while(root)
        {
            if(key < root->val)
            {
                if(root->left and root->left->val == key) 
                {
                    root->left = reorganize(root->left);
                    break;
                }
                else root = root->left;                
            }
            else
            {
                if(root->right and root->right->val == key) 
                {
                    root->right = reorganize(root->right);
                    break;
                }
                else root = root->right;  
            }
        }
        
        return head;
    }

private:
    TreeNode* reorganize(TreeNode* node)
    {
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        
        TreeNode* right = node->right;
        TreeNode* lastRight = findlastRight(node->left);
        lastRight->right = right;
        return node->left;        
    }
    
    TreeNode* findlastRight(TreeNode* node)
    {
        if(node->right == NULL) return node;
        return findlastRight(node->right);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};