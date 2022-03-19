/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   using N = TreeNode;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<N*, N*> parent;
        markParent(root, parent);
        
        unordered_map<N*, bool> visited;
        queue<N*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            if(dist++ == k) break;
            
            for(int i=0; i<n; i++)
            {
                N* front = q.front();     q.pop();
                if(front->left and !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right and !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(parent[front] and !visited[parent[front]])
                {
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            N* front = q.front(); q.pop();
            ans.push_back(front->val);
        }
        
        return ans;
    }
    
    void markParent(N* root, unordered_map<N*, N*> &parent)
    {
        queue<N*> q;
        q.push(root);           
        while(!q.empty())
        {
            N *front = q.front();   q.pop();
            if(front->left) 
            {
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right)
            {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
    }
};