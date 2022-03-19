1. Mark the Parent Nodes using Map while traversing the tree using BFS travel (Using a queue).

```
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

```

2. Pick the given target node and start travelling a distance 1 every iteration. When dist reaches K we come out of the while loop and the nodes that remain in the queue are our answer.
While travelling, start from target node, 
Step #:- mark it as visited and push its children and parent node in the queue and mark them as visited.
Do step # for every node using a for loop.

```
unordered_map<N*, bool> visited;
        queue<N*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            if(dist++ == 2) break;
            
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

```





