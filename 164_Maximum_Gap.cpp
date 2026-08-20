#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
          int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        // Minimum possible gap
        int bucketSize = max(1, (mx - mn) / (n - 1));

        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        // Put numbers into buckets
        for (int num : nums) {
            int index = (num - mn) / bucketSize;

            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
            used[index] = true;
        }

        int ans = 0;
        int prevMax = mn;

        // Find maximum gap between adjacent non-empty buckets
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i])
                continue;

            ans = max(ans, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return ans;
    }
};