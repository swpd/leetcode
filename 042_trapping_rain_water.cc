class Solution {
public:
    int trap(int A[], int n) {
        int water = 0;
        int l = 0, r = n - 1;
        while (l < n - 1 && A[l] <= A[l + 1]) l++;
        while (r > 0 && A[r] <= A[r - 1]) r--;
        while (l < r) {
            if (A[l] < A[r]) {
                int h = A[l];
                while (A[l] <= h && l < r) {
                    water += (h - A[l]);
                    l++;
                }
            } else {
                int h = A[r];
                while (A[r] <= h && l < r) {
                    water += (h - A[r]);
                    r--;
                }
            }
        }
        return water;
    }
};
