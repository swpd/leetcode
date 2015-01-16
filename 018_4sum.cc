class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        int len = num.size();
        for (int i = 0; i < len - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < len - 2; ++j) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int remain = target - num[i] - num[j];
                int start = j + 1, end = len - 1;
                while (start < end) {
                    int sum = num[start] + num[end];
                    if (sum == remain) {
                        vector<int> quad;
                        quad.push_back(num[i]);
                        quad.push_back(num[j]);
                        quad.push_back(num[start]);
                        quad.push_back(num[end]);
                        ans.push_back(quad);
                        while (start < end && num[start] == num[start + 1]) start++;
                        start++;
                        while (start < end && num[end] == num[end - 1]) end--;
                        end--;
                    } else if (sum < remain) {
                        while (start < end && num[start] == num[start + 1]) start++;
                        start++;
                    } else {
                        while (start < end && num[end] == num[end - 1]) end--;
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
