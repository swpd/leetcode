class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) return true;
        int can_reach = 0;
        for (int i = 0; i < n && i <= can_reach; ++i) {
            if (i + A[i] > can_reach) can_reach = i + A[i];
            if (can_reach >= n - 1) return true;
        }
        return false;
    }
};
