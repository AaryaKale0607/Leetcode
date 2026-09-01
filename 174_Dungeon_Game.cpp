#include <vector>
#include<algorithm>
#include<climits>

using namespace std ;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
         int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // Extra cells to simplify boundary conditions
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                int nextHealth = min(dp[i + 1][j], dp[i][j + 1]);

                // Health required before entering current cell
                dp[i][j] = max(1, nextHealth - dungeon[i][j]);
            }
        }

        return dp[0][0]; 
    }
};