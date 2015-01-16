class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        int len = num.size();
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int target = 0 - num[i];
            int start = i + 1, end = len - 1;
            while (start < end) {
                int sum = num[start] + num[end];
                if (sum == target) {
                    vector<int> tri;
                    tri.push_back(num[i]);
                    tri.push_back(num[start]);
                    tri.push_back(num[end]);
                    ans.push_back(tri);
                    while (start < end && num[start] == num[start + 1]) start++;
                    start++;
                    while (start < end && num[end] == num[end - 1]) end--;
                    end--;
                } else if (sum < target) {
                    while (start < end && num[start] == num[start + 1]) start++;
                    start++;
                } else {
                    while (start < end && num[end] == num[end - 1]) end--;
                    end--;
                }
            }
        }
        return ans;
    }
};
