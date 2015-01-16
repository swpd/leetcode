class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size();
        if (n <= 3) {
            int closest = 0;
            for (int i = 0; i < n; ++i) closest += num[i];
            return closest;
        }
        int closest = num[0] + num[1] + num[2];
        for (int i = 0; i < n - 2; ++i) {
            int start = i + 1, end = n - 1;
            while (start < end) {
                int sum = num[i] + num[start] + num[end];
                if (abs(sum - target) < abs(closest - target)) closest = sum;
                if (sum == target) return closest;
                if (sum < target) start++;
                if (sum > target) end--;
            }
        }
        return closest;
    }
};
