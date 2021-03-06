class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int min = num[0];
        int left = 0, right = n - 1;
        while (left <= right) {
            if (num[left] <= num[right]) {
                if (num[left] < min) min = num[left];
                break;
            } else {
                int mid = (left + right) / 2;
                if (num[mid] < num[left]) right = mid;
                else left = mid + 1;
            }
        }
        return min;
    }
};
