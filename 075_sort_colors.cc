class Solution {
public:
    void sortColors(int A[], int n) {
        int red_idx = 0, blue_idx = n - 1;
        int i = 0;
        while (i < blue_idx + 1) {
            if (A[i] == 0) {
                std::swap(A[i], A[red_idx]);
                red_idx++;
                i++;
            } else if (A[i] == 1) i++;
            else if (A[i] == 2) {
                std::swap(A[i], A[blue_idx]);
                blue_idx--;
            }
        }
    }
};
