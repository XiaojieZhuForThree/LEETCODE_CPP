#include <map>
#include <vector>
#include <algorithm>
using std::map;
using std::vector;
using std::max;

class Solution {
public:
    const int MOD = 1e9 + 7;
    map<int, vector<int>> adjList;
    int assignEdgeWeights(const vector<vector<int>>& edges) {
        adjList.clear();
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int maxDepthVal = dfs(1, 0);

        if (maxDepthVal == 0) {
            return static_cast<int>(modularInverse(2));
        } else {
            long long exponent = maxDepthVal - 1;
            return static_cast<int>(power(2, exponent));
        }
    }
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modularInverse(long long n) {
        if (n == 2) return (MOD + 1LL) / 2;
        return power(n, MOD - 2);
    }

    int dfs(int currentNode, int parentNode) {
        int maxSubtreeDepth = 0;
        if (adjList.count(currentNode)) {
            for (int neighbor : adjList.at(currentNode)) {
                if (neighbor == parentNode) continue;
                maxSubtreeDepth = max(maxSubtreeDepth, dfs(neighbor, currentNode) + 1);
            }
        }
        return maxSubtreeDepth;
    }
};
