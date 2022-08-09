class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty()) return 0;     // if there is no orange.
        
        int countFreshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; // queue to store the index of the cell where rotten oranges are placed.

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    countFreshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        // Offset array
        vector<pair<int, int>> dirs = {     {0, 1}, {1, 0}, {-1, 0}, {0, -1}    };

        while (countFreshOranges != 0 && !q.empty())
        {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++)
            {
                int rottenI = q.front().first;
                int rottenJ = q.front().second;
                q.pop();

                for (auto d : dirs)
                {
                    int newI = rottenI + d.first;
                    int newJ = rottenJ + d.second;
                    // if we got any fresh orange adjacent to the rotten orange then it will get rotten and
                    // count of fresh oranges will reduce and we will push the new index of rotten orange in 
                    // the queue.
                    if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1)
                    {
                        grid[newI][newJ] = 2;
                        countFreshOranges--;
                        q.push({newI, newJ});
                    }
                }
            }
            time++;
        }
        
        return countFreshOranges == 0 ? time : -1;
    }
};