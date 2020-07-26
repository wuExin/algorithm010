class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        if(m == 0) return 0;
        int count = 0;
        vector<int> visited(m,0);
        for(int i = 0;i < m;i++) {
            if(visited[i] == 0) {
                dfs(M,visited,i);
                count ++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& M,vector<int>& visited,int i) {
        for(int j = 0;j < visited.size();j++) {
            if(M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M,visited,j);
            }
        }
    }
};