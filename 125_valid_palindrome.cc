class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (!isalnum(s[left])) left++;
            else if (!isalnum(s[right])) right--;
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    ans = false;
                    break;
                }
                left++;
                right--;
            }
        }
        return ans;
    }
};
