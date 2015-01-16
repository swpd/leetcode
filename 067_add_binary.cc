class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int an = a.size(), bn = b.size();
        int n = max(an, bn);
        for (int i = 0; i < n; ++i) {
            int ai = i < an ? a[i] - '0' : 0;
            int bi = i < bn ? b[i] - '0' : 0;
            int val = ai + bi + carry;
            carry = 0;
            if (val >= 2) {
                val %= 2;
                carry = 1;
            }
            sum += (val + '0');
        }
        if (carry) sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
