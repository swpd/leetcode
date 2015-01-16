class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            double sqrt = pow(x, n / 2);
            return sqrt * sqrt;
        } else {
            if (n > 0) {
                double sqrt = pow(x, (n - 1) / 2);
                return sqrt * sqrt * x;
            } else {
                double sqrt = pow(x, (n + 1) / 2);
                return sqrt * sqrt / x;
            }
        }
    }
};
