class Solution {
public:
    vector<int> str2array(string &num) {
        vector<int> array;
        int len = (num.size() - 1) / 4;
        reverse(num.begin(), num.end());
        for (int i = 0; i < len; ++i) {
            array.push_back(0);
            for (int j = 3; j >= 0; --j) array[i] = array[i] * 10 + (num[i * 4 + j] - '0');
        }
        array.push_back(0);
        for (int j = (num.size() - 1) % 4; j >= 0; --j) array[len] = array[len] * 10 + (num[len * 4 + j] - '0');
        return array;
    }
    
    string multiply(string num1, string num2) {
        vector<int> i1 = str2array(num1);
        vector<int> i2 = str2array(num2);
        int len1 = i1.size();
        int len2 = i2.size();
        vector<int> product;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (i + j + 1 > product.size()) product.push_back(0);
                product[i + j] += i1[i] * i2[j];
                if (product[i + j] >= 10000) {
                    if (i + j + 2 > product.size()) product.push_back(0);
                    product[i + j + 1] += product[i + j] / 10000;
                    product[i + j] %= 10000;
                }
            }
        }
        int len_pro = product.size();
        stringstream ans;
        int i = len_pro - 1;
        for (; i >= 0; --i) {
            if (product[i] != 0 || i == 0) {
                ans << product[i];
                i--;
                break;
            }
        }
        for (; i >= 0; --i) ans << setw(4) << setfill('0') << product[i];
        return ans.str();
    }
};
