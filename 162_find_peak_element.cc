class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n == 1) return 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == 0) {
                if (num[mid] > num[mid + 1]) return mid;
                else left = mid + 1;
            } else if (mid == n - 1) {
                if (num[mid] > num[mid - 1]) return mid;
                else right = mid - 1;
            } else {
                if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) return mid;
                else if (num[mid] < num[mid - 1]) right = mid - 1;
                else if (num[mid] < num[mid + 1]) left = mid + 1; 
            }
        }
        return -1;
    }
};
