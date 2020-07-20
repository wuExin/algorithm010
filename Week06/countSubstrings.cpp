class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        int res = s.length();
        for(int i = n-1;i >=0;i--) {
            for(int j = i + 1;j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - 1 == 1) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = false;
                if(dp[i][j]) res++;
            }
        }
        return res;   
    }
};