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
        
        // Taking a map for all the visited nodes
        unordered_map<N*, bool> visited;
        queue<N*> q;
        // Push the target node in the queue
        q.push(target);
        // Mark the target node visited
        visited[target] = true;
        // Taking distance = 0
        int dist = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            // If distance traversed is equal to k, we break out of loop 
            if(dist++ == k) break;
            
            for(int i=0; i<n; i++)
            {
                N* node = q.front();     q.pop();
                
                // If left child exists and we have not visited it
                if(node->left and !visited[node->left])
                {
                    // Push the left child in the queue and mark it visited
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                // If right child exists and we have not visited it
                if(node->right and !visited[node->right])
                {
                    // Push the right child in the queue and mark it visited
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // If Parent node exists and we have not visited it. 
                // For example if target node is our root...its parent doesnt exists, so it is better to check if it exists or not
                if(parent[node] and !visited[parent[node]])
                {
                    // Push parent node in the queue and mark it visited
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        // After breaking out of loop if distance == k, the remaining nodes in queue is our answer
        // Add the remaining nodes to the vector
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
        // Mark parents of all the nodes in the unordered map
        
        queue<N*> q;
        q.push(root);           
        while(!q.empty())
        {
            N *node = q.front();   q.pop();
            if(node->left) 
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
};