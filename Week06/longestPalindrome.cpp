class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        string res = {s[0]};
        for(int i = n - 1;i >=0;i--) {
            for(int j = i + 1;j < n;j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = false;
                if(dp[i][j] && res.length() <= j - i) {
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;    
    }
};