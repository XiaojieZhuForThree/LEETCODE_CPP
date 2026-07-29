#include <numeric>
#include <array>
#include <span>
#include <string>
using std::accumulate;
using std::array;
using std::span;
using std::string;

constexpr long long MAX = 400000000;
class Solution {
public:
    long long C(long long n, long long x) {
        long long tmp = 1;
        if (n - x < x) x = n - x;
        for (int i = 1; i <= x; i++) {
            tmp *= (n + 1 - i);
            tmp /= i;
            if (tmp >= MAX) return MAX;
        }
        return tmp;
    }
    long long how_many(const array<int, 26> &cnt) {
        int n = accumulate(cnt.begin(), cnt.end(), 0);
        long long ans = 1;
        for (int x : cnt) if (x) {
            ans *= C(n, x);
            n -= x;
            if (ans >= MAX) return MAX;
        }
        if (ans < 0) printf("WAT\n");
        return ans;
    }
    bool f(span<char> sp, int k) {
        array<int, 26> cnt{0};
        for (char c : sp) cnt[c-'a']++;
        if (how_many(cnt) <= k) return false;
        // let's find every position...
        long long N = accumulate(cnt.begin(), cnt.end(), 0ll);
        for (char &c : sp) {
            // which character?
            const long long how = how_many(cnt);
            for (int i = 0; i < 26; i++) if (cnt[i]) {
                // how many are there with i at the first position?
                const long long without = (how == MAX) ? MAX : ((how * (long long)cnt[i]) / N);
 
                if (without > k) {
                    c = i + 'a';
                    cnt[i]--;
                    break;
                }
                k -= without;
            }
            N--;
        }

        return true;
    }

    string smallestPalindrome(string s, int k) {
        const int NN = s.size();
        const int N = NN / 2;
        if (!f({s.begin(), s.begin() + N}, k-1)) return "";
        copy(s.begin(), s.begin() + N, s.rbegin());
        return s;
    }
};
