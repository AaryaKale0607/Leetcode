#include <vector>
#include <climits>
using namespace std ;
class Solution {
public:
    int numSquares(int n) {
        // dp[i] = minimum number of perfect squares
        // needed to make sum i

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                int square = j * j;

                dp[i] = min(dp[i],
                            1 + dp[i - square]);
            }
        }

        return dp[n];
    }
};