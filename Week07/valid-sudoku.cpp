class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         vector<unordered_map<int,int>> rows(9,unordered_map<int,int>());   
         vector<unordered_map<int,int>> cols(9,unordered_map<int,int>());
         vector<unordered_map<int,int>> boxes(9,unordered_map<int,int>());
         for(int i = 0;i < 9;i++) {
             for(int j = 0;j < 9;j++) {
                if(board[i][j] != '.') {
                    int k = (i/3)*3 + j/3;
                    int num = board[i][j] - '0' - 1;
                    rows[i][num]++;
                    cols[j][num]++;
                    boxes[k][num]++;
                    if(rows[i][num] > 1 || cols[j][num] > 1 || boxes[k][num] > 1) return false;    
                }
             }
         }    
         return true;
    }
};