class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int max_area = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            max_area = max(h * w, max_area);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return max_area;
    }
};
