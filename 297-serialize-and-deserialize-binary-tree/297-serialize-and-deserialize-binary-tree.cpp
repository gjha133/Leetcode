/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using N = TreeNode;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(N* root) {
        string res = "";
        buildString(root, res);
        //cout << res;
        return res;       
    }

    // Decodes your encoded data to tree.
    N* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        
        // This for loop remove ',' from the string and pushes the string in the queue
        // 1, 2, 3, null, null, 4, 5 ---->>>>> Inside queue = |1 2 3 null null 4 5|
        
        for(char c: data) 
        {
            if(c != ',') s += c;
            else
            {
                q.push(s);
                s = "";
            }
        }        
        return buildTree(q);
    }
    
    
private:
    void buildString(N* root, string &res)
    {
        if(root == NULL)
        {   res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    N* buildTree(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null") return NULL;
        
        N* root = new N(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));