class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            n--;
            char digit = n % 26 + 'A';
            ans = digit + ans;
            n /= 26;
        }
        return ans;
    }
};
