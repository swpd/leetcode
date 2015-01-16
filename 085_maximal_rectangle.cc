class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix[0].size();
        vector<int> height(c, 0);
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            stack<int> stk;
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
                if (stk.empty() || height[stk.top()] <= height[j]) stk.push(j);
                else {
                    while (!stk.empty() && height[stk.top()] > height[j]) {
                        int curr_height = height[stk.top()];
                        stk.pop();
                        int left_idx = stk.empty() ? 0 : (stk.top() + 1);
                        int area = curr_height * (j - left_idx);
                        if (area > ans) ans = area;
                    }
                    stk.push(j);
                }
            }
            while (!stk.empty()) {
                int curr_height = height[stk.top()];
                stk.pop();
                int left_idx = stk.empty() ? 0 : (stk.top() + 1);
                int area = curr_height * (c - left_idx);
                if (area > ans) ans = area;
            }
        }
        return ans;
    }
};
