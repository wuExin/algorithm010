class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1,false);
        for(int i = 2 ; i < N + 1; i++) {
            for(int j = 1; j*j <i;j++) {
                if(i%j == 0 & !dp[i - j]) dp[i] = true;
            }
        }
        return dp[N];
    }
};