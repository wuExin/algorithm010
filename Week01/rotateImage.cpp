class Solution {
public:
    void rotate (vector<vector<int>>& matrix) {
        diagonalRotation(matrix);
        horizontalRotation(matrix);
    }
    void diagonalRotation (vector<vector<int>>& matrix) {
        int row = matrix.size() - 1;
        int col = matrix.at(0).size() - 1;
        for (int i = 0;i <= row;i++) {
            for (int j = i;j <= col;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    void horizontalRotation (vector<vector<int>>& matrix) {
        int row = matrix.size() - 1;
        int col = matrix.size() - 1;
        for (int i = 0; i<= row;i++) {
            for (int j = 0;j<= col/2;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col - j];
                matrix[i][col - j] = temp;                
            }
        }
    }
};

