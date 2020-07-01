class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
          int count = 0;
          for (int i = 0;i < grid.size();i++) {
              for (int j = 0;j<grid[i].size();j++) {
                  if (grid[i][j] == '1') {
                      dfsMarking(grid,i,j);
                      count++;
                  }
              }
          }
          return count;
    }
    void dfsMarking(vector<vector<char>>& grid,int i,int j) {
        if (i<0 || j<0 || i>= grid.size() || j >= grid[i].size()) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfsMarking(grid,i-1,j);
        dfsMarking(grid,i+1,j);
        dfsMarking(grid,i,j-1);
        dfsMarking(grid,i,j+1);
    }
};