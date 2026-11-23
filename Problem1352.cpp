#include <vector>
using std::vector;

class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        if (num == 0)  v.clear();
        else if (size(v) == 0) v.push_back(num);
        else v.push_back(v[size(v) - 1] * num); 
    }
    
    int getProduct(int k) {
        int n = size(v);
        if (k > n) return 0;
        return v[n - 1] / (n - k - 1 >= 0 ? v[n - k - 1] : 1);
    }
};