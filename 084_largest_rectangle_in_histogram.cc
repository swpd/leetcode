class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n =  height.size();
        int ans = 0;
        // maintain the left index, always strictly ascendant
        stack<int> stk;
        for (int i = 0; i < n; ) {
            if (stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i);
                i++;
            } else if (height[stk.top()] > height[i]) {
                while (!stk.empty() && (height[stk.top()] > height[i])) {
                    int curr_height = height[stk.top()];
                    stk.pop();
                    int left_idx = stk.empty() ? 0 : (stk.top() + 1);
                    int area = curr_height * (i - left_idx);
                    if (area > ans) ans = area;
                }
            }
        }
        while (!stk.empty()) {
            int curr_height = height[stk.top()];
            stk.pop();
            int left_idx = stk.empty() ? 0 : (stk.top() + 1);
            int area = curr_height * (n - left_idx);
            if (area > ans) ans = area;
        }
        return ans;
    }
};
