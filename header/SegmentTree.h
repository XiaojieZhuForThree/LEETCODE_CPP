#pragma once

#include <vector>
#include <cassert>

class SegmentTree {
    std::vector<int> tree;
    int n = 0;

    void build(int idx, int l, int r, const std::vector<int>& vals) {
        if (l == r) {
            tree[idx] = vals[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(idx * 2 + 1, l, m, vals);
        build(idx * 2 + 2, m + 1, r, vals);
        tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

    int query_helper(int idx, int tl, int tr, int l, int r) const {
        if (tr < l || tl > r) return 0;
        if (tl >= l && tr <= r) return tree[idx];
        int m = tl + (tr - tl) / 2;
        return query_helper(idx * 2 + 1, tl, m, l, r) + query_helper(idx * 2 + 2, m + 1, tr, l, r);
    }

    void update_helper(int idx, int tl, int tr, int ti, int val) {
        if (tl == tr) {
            tree[idx] = val;
            return;
        }
        int m = tl + (tr - tl) / 2;
        if (ti <= m) update_helper(idx * 2 + 1, tl, m, ti, val);
        else update_helper(idx * 2 + 2, m + 1, tr, ti, val);
        tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

public:
    SegmentTree(const std::vector<int>& v) : n(static_cast<int>(v.size())) {
        assert(!v.empty() && "SegmentTree: input vector cannot be empty");
        tree.resize(4 * n, 0);
        build(0, 0, n - 1, v);
    }

    int query(int l, int r) const {
        assert(l >= 0 && r < n && l <= r && "SegmentTree: invalid query range");
        return query_helper(0, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        assert(idx >= 0 && idx < n && "SegmentTree: index out of bounds");
        update_helper(0, 0, n - 1, idx, val);
    }
};
