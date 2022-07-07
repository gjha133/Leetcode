{
q.push(s);
s = "";
}
else s += c;
}
return buildTree(q);
}
private:
N* buildTree(queue<string> &q)
{
string s = q.front();
q.pop();
if(s == "~") return NULL;
N* root = new N(stoi(s));
root->left = buildTree(q);
root->right = buildTree(q);
return root;
}
};
​
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));