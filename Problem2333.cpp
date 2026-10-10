#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(100001);
        for(int i=0; i<n; i++) diff[abs(nums1[i] - nums2[i])]++;

        int k = k1+k2;
        for(int i= diff.size()-1; i >= 0 && k > 0; i--){
            if(diff[i]){
                int mini = min(diff[i], k);
                k -= mini;
                diff[i] -= mini;

                int newAbsDiff  = i-1;
                if(newAbsDiff > 0) diff[newAbsDiff] += mini;
            }
        }

        long long res = 0;
        for(int i=0; i < diff.size(); i++){
            long long num = i, times = diff[i];
            res += (long long) num * num * times;
        }
        return res;
    }
};
