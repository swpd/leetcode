class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> left(n, 0), right(n, 0);
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n; ++i) {
            int profit = prices[i] - min_price;
            if (profit > max_profit) max_profit = profit;
            left[i] = max_profit;
            if (min_price > prices[i]) min_price = prices[i];
        }
        int max_price = prices[n - 1];
        max_profit = 0;
        for (int i = n - 2; i >= 0; --i) {
            int profit = max_price - prices[i];
            if (profit > max_profit) max_profit = profit;
            right[i] = max_profit;
            if (max_price < prices[i]) max_price = prices[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] + right[i] > ans) ans = left[i] + right[i];
        }
        return ans;
    }
};
