#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (vector<char> r : board) {
            std::unordered_set<char> s;
            for (char c : r) {
                if (c == '.') continue;
                if (s.count(c)) return false;
                s.insert(c);
            }
        }
        for (int j = 0; j < 9; j++) {
            std::unordered_set<char> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                std::unordered_set<char> s;
                for (int m = i; m < i + 3; m++) {
                    for (int n = j; n < j + 3; n++) {
                        if (board[m][n] == '.') continue;
                        if (s.count(board[m][n])) return false;
                        s.insert(board[m][n]);
                    }
                }
            }
        }
        return true;
    }
};