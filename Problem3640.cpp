#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    long long maxSumTrionic(vector<int> &nums)
    {
        nums.push_back(INT_MIN);

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = nums[i] + prefix[i];
        }

        long long maxSum = -1e15;

        int prevIncIdx = -1;
        int currIncIdx = -1;
        bool isInc = false;

        for (int i = 0; i < n - 1; i++)
        {
            int currEle = nums[i];
            int nextEle = nums[i + 1];

            if (currEle < nextEle)
            {
                if (!isInc)
                {
                    isInc = true;
                    currIncIdx = i;
                }
                if (prevIncIdx != -1)
                {
                    maxSum = std::max(maxSum,
                                      prefix[i + 2] - prefix[prevIncIdx]);
                }
            }
            else if (nextEle < currEle)
            {
                if (isInc)
                {
                    prevIncIdx = currIncIdx;
                }
                isInc = false;
            }
            else
            {
                prevIncIdx = -1;
                isInc = false;
                currIncIdx = -1;
            }
            while (
                prevIncIdx != -1 &&
                prevIncIdx + 2 < n &&
                nums[prevIncIdx + 1] < nums[prevIncIdx + 2] &&
                nums[prevIncIdx] < 0)
            {
                prevIncIdx++;
            }
        }

        return maxSum;
    }
};