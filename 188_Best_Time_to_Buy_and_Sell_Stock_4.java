class Solution {
    public int maxProfit(int k, int[] prices) {
         int n = prices.length;

        if (n == 0 || k == 0) {
            return 0;
        }

        // If k is large enough, it becomes the unlimited transactions case
        if (k >= n / 2) {
            int profit = 0;

            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }

            return profit;
        }

        // dp[t][0] = maximum profit after at most t transactions,
        //             currently NOT holding a stock
        // dp[t][1] = maximum profit after at most t transactions,
        //             currently holding a stock
        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];

        for (int t = 1; t <= k; t++) {
            buy[t] = Integer.MIN_VALUE;
        }

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = Math.max(buy[t], sell[t - 1] - price);
                sell[t] = Math.max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
}