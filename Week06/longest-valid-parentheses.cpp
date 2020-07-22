class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.length();
        int maxValue = 0;
        vector<int> dp(length,0);
        for(int i = 1; i< length;i++) {
            if(s[i] == '(') dp[i] = 0;
            else {
                if(s[i-1] == '(') dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                } 
            }
            maxValue = max(maxValue,dp[i]);
        }
        return maxValue; 
    }
};