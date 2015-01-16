/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start || i1.start == i2.start && i1.end < i2.end;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<Interval> ans;
        if (n == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < n; ++i) {
            if (ans.empty()) ans.push_back(intervals[i]);
            else {
                if (intervals[i].start <= ans.back().end) {
                    ans[ans.size() - 1].end = max(intervals[i].end, ans.back().end);
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};
