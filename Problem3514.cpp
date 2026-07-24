#include <vector>
#include <numeric>
using std::vector;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi = 2048;

        vector<char> pairXor(maxi, 0);
        vector<char> tripletXor(maxi, 0);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) pairXor[nums[i] ^ nums[j]] = 1;
        }

        for (int x = 0; x < maxi; x++) {
            if (!pairXor[x]) continue;
            for (int value : nums) tripletXor[x ^ value] = 1;
        }
        return accumulate(tripletXor.begin(), tripletXor.end(), 0);
    }
};
