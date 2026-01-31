#include <vector>
using std::vector;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char c : letters) {
            if (c > target) return c;
        }
        return letters[0];
    }
};