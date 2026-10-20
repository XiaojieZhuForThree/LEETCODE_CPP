#include <vector>
using std::vector;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> divisor;
        for (int i = 1; i <= n / 2; i++) {
            if(n % i == 0) divisor.push_back(i);   
        }
        divisor.push_back(n);
        int ans=0;
        for (int i = 0; i < divisor.size(); i++) {
            int j=0;
            bool temp=false;
            while (j < n - 1) {
                if (j + divisor[i] < n) {
                    int maxi = *max_element(nums.begin() + j, nums.begin() + j + divisor[i]);
                    int z = j + divisor[i];
                    int mini = *min_element(nums.begin() + z, nums.begin() + z + divisor[i]);
                    if (maxi > mini){
                        temp = true;
                        break;
                    }
                }
                int cnt=0;
                for(int k=j;k<j+divisor[i]-1;k++){
                    if(nums[k] > nums[k+1]) cnt++;
                }
                if (nums[j + divisor[i] - 1] > nums[j]) cnt++;
                if (cnt > 1) {
                    temp=true;
                    break;
                }
                j += divisor[i];
            }
            if (!temp) ans += divisor[i];
        }
        return ans;
    }
};
