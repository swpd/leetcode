/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> m;
            int vertical = 0;
            int dup = 0;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (points[j].x == points[i].x) {
                    if (vertical == 0) vertical = 2;
                    else vertical += 1;
                    if (ans < vertical) ans = vertical;
                    if (points[j].y == points[i].y) dup++;
                } else {
                    double slope = (double) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                    if (m.find(slope) == m.end()) m[slope] = 2;
                    else m[slope] += 1;
                }
            }
            for (unordered_map<double, int>::iterator it = m.begin(); it != m.end(); ++it) {
                if (it->second + dup > ans) ans = it->second + dup;
            }
        }
        return ans;
    }
};
