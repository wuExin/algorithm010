class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.at(0).size();
        vector<vector<int>> count(m,vector<int>(n,grid[0][0]));
        for(int i = 1; i < m; i++) {
            count[i][0] = count[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++) {
            count[0][i] = count[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1;j< n; j++) {
                count[i][j] = min(count[i-1][j],count[i][j-1]) + grid[i][j];    
            }
        }
        return count[m-1][n-1];              
    }
};