class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        queue<pair<int,int>> gridQueue;
        vector<vector<int>> visited(n,vector<int>(n,0));
        const vector<vector<int>> DIRS{{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                                       {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        int distance = 1;
        gridQueue.emplace(0, 0);
        while(not gridQueue.empty()) {
            int size = gridQueue.size();
            while(size--) {
                auto [x,y] = gridQueue.front();
                gridQueue.pop();
                if(x == n - 1  && y == n - 1) return distance;
                for(const auto& d : DIRS) {
                    int dx = x + d[0];
                    int dy = y + d[1];
                    if(dx < 0 || dy < 0 || dx >= n || dy >= n || 
                    grid[dx][dy] == 1 || visited[dx][dy] == 1) continue;
                    visited[dx][dy] = 1;
                    gridQueue.emplace(dx,dy);                    
                }
            }
            distance++;
        }
        return -1;
    }
};