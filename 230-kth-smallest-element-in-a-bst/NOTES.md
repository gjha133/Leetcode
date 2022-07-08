```
N* node = root;
stack<N*> st;
int count = 0;
while(1)
{
if(node) {st.push(node); node = node->left;}
else
{
if(st.empty()) break;
node = st.top(); st.pop();
if(++count == k) return node->val;
node = node->right;
}
}
return 0;
```