class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = -1, end = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] < target) l = mid + 1;
            else if (A[mid] > target) r = mid - 1;
            else {
                if (start == -1 || start > mid) start = mid;
                r = mid - 1;
            }
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] < target) l = mid + 1;
            else if (A[mid] > target) r = mid - 1;
            else {
                if (end == -1 || end < mid) end = mid;
                l = mid + 1;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
