class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
         vector<vector<int>> count(triangle.size(),vector<int>(triangle.size(),0));     
         return dfs(count,triangle,0,0);
    }

    int dfs(vector<vector<int>>& count,vector<vector<int>>& triangle,int i,int j) {
        if(i == triangle.size()) {
            return 0;
        }
        if(count[i][j] == 0) {
            count[i][j] = min(dfs(count,triangle,i+1,j+1),dfs(count,triangle,i+1,j)) + triangle[i][j];
        }
        return count[i][j];
    }
};