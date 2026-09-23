#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ;
        int sum = 0 ;
        for (int i = 0 ; i < nums.size() ; i++){
            sum += nums[i] ;
        }
        int target = sum - x ;
        if (target < 0) return -1 ;
        if (target == 0) return n ;

        int left = 0 ;
        int right = 0 ;
        int curr = 0 ;
        int operation = INT_MAX ;
        while(right < n){
            curr += nums[right] ;
            right++ ;
            while(curr > target && left < n){
                curr -= nums[left] ;
                left++ ;
            }
            if (curr == target){
                operation = min(operation , n-(right-left)) ;
            }
        }
        if (operation == INT_MAX) return -1 ;
        return operation ;
    }
};
