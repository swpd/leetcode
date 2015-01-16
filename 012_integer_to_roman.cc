class Solution {
public:
    string intToRoman(int num) {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int n = sizeof(val) / sizeof(int);
        string ans;
        for (int i = 0; i < n; ++i) {
            int cnt = num / val[i];
            num = num % val[i];
            for (int j = 0; j < cnt; ++j) ans += sym[i];
        }
        return ans;
    }
};
