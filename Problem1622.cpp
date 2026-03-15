#include <vector>
using std::vector;

class Fancy {
public:
    class node {
    public:
        node* left = nullptr;
        node* right = nullptr;
        int l, r;
        long long add = 0;
        long long mul = 1;
    };

    int size = 0;
    node* root;
    vector<long long> arr;
    const int MOD = 1e9 + 7;

    Fancy() {
        root = new node();
        root->l = 0;
        root->r = 1e5;
    }

    void update(node* curr) {
        int l = curr->l, r = curr->r;
        if (l == r) return;
        int mid = l + (r - l) / 2;
        if (size <= mid) {
            if (!curr->left) {
                curr->left = new node();
                curr->left->l = l;
                curr->left->r = mid;
            }
            update(curr->left);
        } else {
            if (!curr->right) {
                curr->right = new node();
                curr->right->l = mid + 1;
                curr->right->r = r;
            }
            update(curr->right);
        }
    }

    long long get(node* curr, long long mul, long long extra, int i) {
        extra = (extra + curr->add * mul) % MOD;
        mul = (mul * curr->mul) % MOD;
        int l = curr->l, r = curr->r;
        if (l == r) {
            return (arr[l] * mul + extra) % MOD;
        }
        int mid = l + (r - l) / 2;
        if (i <= mid) {
            return get(curr->left, mul, extra, i);
        } else {
            return get(curr->right, mul, extra, i);
        }
    }

    void add(node* curr, int val) {
        if (!curr) return;
        int l = curr->l, r = curr->r;
        if (l >= size) return;
        if (r < size) {
            curr->add = (curr->add + val) % MOD;
            return;
        }
        add(curr->left, val);
        add(curr->right, val);
    }

    void mul(node* curr, int val) {
        if (!curr) return;
        int l = curr->l, r = curr->r;
        if (l >= size) return;
        if (r < size) {
            curr->add = (curr->add * val) % MOD;
            curr->mul = (curr->mul * val) % MOD;
            return;
        }
        mul(curr->left, val);
        mul(curr->right, val);
    }

    void append(int val) {
        update(root);
        arr.push_back(val);
        size++;
    }

    void addAll(int inc) {
        add(root, inc);
    }

    void multAll(int m) {
        mul(root, m);
    }

    int getIndex(int idx) {
        if (idx >= size) return -1;
        return get(root, 1, 0, idx);
    }
};