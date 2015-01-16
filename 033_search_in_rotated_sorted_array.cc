class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0) return -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) {
                if (A[l] <= A[r]) l = mid + 1;
                else {
                    if (A[mid] > A[r]) l = mid + 1;
                    else {
                        if (target >= A[l]) r = mid - 1;
                        else l = mid + 1;
                    }
                }
            } else {
                if (A[l] <= A[r]) r = mid - 1;
                else {
                    if (A[mid] < A[r]) r = mid - 1;
                    else {
                        if (target < A[l]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
