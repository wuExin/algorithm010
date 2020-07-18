class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> allCount(m,vector<int>(n,0));
        if((m <= 2 && n < 2) || (m < 2 && n <= 2)) {
            return 1;
        }
        return dp(0,0,m,n,allCount);    
    }
    int dp(int i ,int j,int m,int n,vector<vector<int>>& allCount) {
        if((i == m - 2 && j == n - 1) || (i == m - 1 && j == n - 2)) {
            allCount[i][j] = 1;
            return allCount[i][j];
        }
        if(allCount[i][j] == 0) {
            if(i == m - 1) {
                allCount[i][j] = dp(i,j+1,m,n,allCount);
            }
            else if(j == n - 1) {
                allCount[i][j] = dp(i+1,j,m,n,allCount);
            }
            else {
                allCount[i][j] = dp(i+1,j,m,n,allCount) + dp(i,j+1,m,n,allCount);
            }
        }    
        return allCount[i][j];
    }
};