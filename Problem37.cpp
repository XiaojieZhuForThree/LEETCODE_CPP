#include <vector>
using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
private:
    bool dfs(vector<vector<char>>& board, int i , int j) {
        if (i == 9) return true;
        if (j == 9) return dfs(board, i + 1 , 0);
        if (board[i][j] != '.') return dfs(board, i, j + 1);
        for (char c = '1'; c <= '9'; c++) {
            if (!yes(board, i, j, c)) continue;
            board[i][j] = c;
            if (dfs(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool yes(vector<vector<char>>& board, int i, int j, int c) {
        for (int m = 0; m < 9; m++) {
            if (board[i][m] == c) return false;
        }
        for (int m = 0; m < 9; m++) {
            if (board[m][j] == c) return false;
        }
        int m = (i / 3) * 3, n = (j / 3) * 3;
        for (int k = 0; k < 3; k++) {
            for (int t = 0; t < 3; t++) {
                if (board[m + k][n + t] == c) return false;
            }
        }
        return true;
    }
};