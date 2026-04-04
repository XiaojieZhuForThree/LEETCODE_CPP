#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = size(encodedText);
        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) mat[i][j] = encodedText[idx++];
        }

        string result = "";

        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;

            while (i < rows && j < cols) {
                result += mat[i][j];
                i++;
                j++;
            }
        }
        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};