class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int max_profit = 0;
        vector<int> diff(n - 1);
        for (int i = n - 2; i >= 0; --i) diff[i] = prices[i + 1] - prices[i];
        for (int i = 0; i < n - 1; ++i)
            if (diff[i] > 0) max_profit += diff[i];
        return max_profit;
    }
};
