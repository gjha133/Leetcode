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
​
```
Finally after travelling and reaching distance = K.
The remaining nodes in the queue are pushed in the vector ans.
```
vector<int> ans;
while(!q.empty())
{
N* front = q.front(); q.pop();
ans.push_back(front->val);
}
​
```
​
​
​
​
​
​