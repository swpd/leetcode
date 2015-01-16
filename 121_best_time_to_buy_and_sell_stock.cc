class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n; ++i) {
            int profit = prices[i] - min_price;
            if (profit > max_profit) max_profit = profit;
            if (min_price > prices[i]) min_price = prices[i];
        }
        return max_profit;
    }
};
