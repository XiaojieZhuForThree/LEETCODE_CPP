#include <unordered_map>
#include <vector>
using std::vector;

class Bank {
public:
    std::unordered_map<int, long long> m;
    Bank(vector<long long>& balance) {
        for (int i = 0; i < size(balance); i++) m[i] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if (!m.count(account1) || m[account1] < money || !m.count(account2)) return false;
        m[account1] -= money;
        m[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if (!m.count(account)) return false;
        m[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if (!m.count(account) || m[account] < money) return false;
        m[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */