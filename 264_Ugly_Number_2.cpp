#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
         vector<int> dp(n);

        dp[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {

            int a = dp[p2] * 2;
            int b = dp[p3] * 3;
            int c = dp[p5] * 5;

            // Select the smallest candidate
            dp[i] = min({a, b, c});

            // Update pointers
            if (dp[i] == a) p2++;
            if (dp[i] == b) p3++;
            if (dp[i] == c) p5++;
        }

        return dp[n - 1];
    }
};