class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        int curr_candy = 1;
        int max_candy = curr_candy;
        int seq_len = 0;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] <= ratings[i]) {
                if (ratings[i - 1] == ratings[i]) curr_candy = 1;
                else curr_candy++;
                ans += curr_candy;
                max_candy = curr_candy;
                seq_len = 0;
            } else {
                seq_len++;
                if (max_candy == seq_len) seq_len++;
                ans += seq_len;
                curr_candy = 1;
            }
        }
        return ans;
    }
};
