class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) {
            return res;
        }
        vector<string> board(n,string(n,'.'));
        traceback(board,0);
        return res;
    }

    void traceback (vector<string>& board,int row) {
        if (board.size() == row) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col< n; col++) {
            if(!isValid(board, row, col)) {
                continue;
            }
            board[row][col] = 'Q';
            traceback(board,row+1);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};