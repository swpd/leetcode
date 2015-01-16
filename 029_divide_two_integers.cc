class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool neg = false;
        if (dividend < 0 ^ divisor < 0) neg = true;
        dividend = abs(dividend);
        divisor = abs(divisor);
        stack<int> s;
        stack<int> times;
        s.push(divisor);
        times.push(1);
        int ans = 0;
        while (!s.empty()) {
            int remain = dividend - s.top();
            if (remain > 0) {
                if (remain < s.top()) {
                    ans += times.top();
                    dividend = remain;
                    times.pop();
                    s.pop();
                } else {
                    times.push(times.top() + times.top());
                    s.push(s.top() + s.top());
                }
            } else if (remain == 0) {
                ans += times.top();
                break;
            } else {
                times.pop();
                s.pop();
            }
        }
        if (neg) return -ans;
        else return ans;
    }
};
