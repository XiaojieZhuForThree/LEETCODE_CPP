#include <vector>
#include <algorithm>
#include <utility>
using std::vector;
using std::max;
using std::min;
using std::pair;


class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int mxF = 0;
        for (auto it : items) {
            mxF = max(mxF, it[0]);
        }
        vector<int> freq(mxF + 1, 0), cnt(mxF + 1, 0);
        for (auto it : items) {
            freq[it[0]]++;
        }
        for (int i = 1; i <= mxF; i++) {
            for (int j = i; j <= mxF; j += i) {
                cnt[i] += freq[j];
            }
        }
        long long m = LLONG_MAX;
        for (auto& it : items) {
            m = min(m, (long long)it[1]);
        }

        vector<pair<long long, long long>> store;

        for (auto it : items) {
            store.push_back({(long long)it[1], (long long)cnt[it[0]] - 1});
        }

        sort(store.begin(), store.end());

        long long r = budget;
        long long total = 0;
        long long lim = 2 * m;

        for (auto it : store) {
            long long a = it.first;
            long long b = it.second;

            if (a >= lim)
                break;
            if (b <= 0)
                continue;
            long long take = min(b, r / a);

            total += 2 * take;
            r -= take * a;
            if (take < b)
                break;
        }
        total += r / m;

        return (int)total;
    }
};
