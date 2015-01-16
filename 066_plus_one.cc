class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        bool carry = true;
        for (int i = n - 1; i >= 0; --i) {
            if (carry) {
                digits[i] += 1;
                carry = false;
                if (digits[i] >= 10) {
                    digits[i] %= 10;
                    carry = true;
                }
            }
        }
        if (carry) digits.emplace(digits.begin(), 1);
        return digits;
    }
};
