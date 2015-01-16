class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0 || n == 1) return 0;
        int min_steps = 0;
        int start = 0, end = 0;
        int next_end = -1;
        while (true) {
            for (int i = start; i <= end; ++i) {
                if (i + A[i] > next_end) next_end = i + A[i];
                if (next_end >= n - 1) return min_steps + 1;
            }
            if (next_end <= end) break;
            min_steps++;
            start = end + 1;
            end = next_end;
        }
        return -1;
    }
};
