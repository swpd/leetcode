class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0) return -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] == target) return true;
            if (A[l] < A[mid]) {
                if (A[l] <= target && target < A[mid]) r = mid - 1;
                else l = mid + 1;
            } else if (A[r] > A[mid]) {
                if (A[mid] < target && target <= A[r]) l = mid + 1;
                else r = mid - 1;
            } else if (A[l] == A[mid]) l++;
            else r--;
        }
        return false;
    }
};
