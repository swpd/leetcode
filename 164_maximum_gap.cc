class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        int min_val = num[0], max_val = num[0];
        for (vector<int>::size_type i = 0; i < n; ++i) {
            min_val = min(num[i], min_val);
            max_val = max(num[i], max_val);
        }
        double gap = (max_val - min_val) * 1.0 / (n - 1);
        vector<int> bucket_min(n - 1, max_val);
        vector<int> bucket_max(n - 1, min_val);
        for (vector<int>::size_type i = 0; i < n; ++i) {
            if (num[i] != min_val && num[i] != max_val) {
                int index = (num[i] - min_val) / gap;
                bucket_min[index] = min(bucket_min[index], num[i]);
                bucket_max[index] = max(bucket_max[index], num[i]);
            }
        }
        int max_gap = std::numeric_limits<int>::min();
        int last_max = min_val;
        for (vector<int>::size_type i = 0; i < n - 1; ++i) {
            if (bucket_min[i] != max_val && bucket_max[i] != min_val) {
                max_gap = max(max_gap, bucket_min[i] - last_max);
                last_max = bucket_max[i];
            }
        }
        max_gap = max(max_gap, max_val - last_max);
        return max_gap;
    }
};
