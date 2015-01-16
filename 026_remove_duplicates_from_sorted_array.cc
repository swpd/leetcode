class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int curr = 0, next = 1;
        while (next < n) {
            if (A[curr] != A[next]) {
                A[curr + 1] = A[next];
                curr++;
            }
            next++;
        }
        return curr + 1;
    }
};
