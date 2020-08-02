class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        if(n <= 0) return count;
        vector<string> board(n,string(n,'.'));
        traceBack(board,0);
        return count;
    }
    void traceBack(vector<string>& board,const int& row) {
        if(board.size() == row) {
            count++;
            return;
        }
        for(int i = 0;i < board[0].length();i++) {
            if(!isVaild(board,row,i))continue;
            board[row][i] = 'Q';
            traceBack(board,row+1);
            board[row][i] = '.';
        }
    }
    bool isVaild(vector<string>& board,const int& row,const int& col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
}; 