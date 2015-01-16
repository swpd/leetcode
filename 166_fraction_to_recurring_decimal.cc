class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) ans += "-";
        long long n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);
        ans += std::to_string(n / d);
        if (n % d == 0) return ans;
        ans += ".";
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator it;
        long long remain = n % d;
        while (remain != 0) {
            it = um.find(remain);
            if (it != um.end()) {
                ans.insert(um[remain], 1, '(');
                ans += ')';
                break;
            }
            um[remain] = ans.size();
            remain *= 10;
            ans += to_string(remain / d);
            remain = remain % d;
        }
        return ans;
    }
};
