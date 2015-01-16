class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int len = 0;
        int origin = x;
        int target = 0;
        while (origin != 0) {
            target = target * 10 + origin % 10;
            origin /= 10;
        }
        return target == x;
    }
};
