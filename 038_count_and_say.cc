class Solution {
public:
    string countAndSay(int n) {
        int nth = 1;
        string s("1");
        while (nth < n) {
            string tmp;
            int len = s.size();
            char cur = s[0];
            int count = 1;
            for (int i = 1; i < len; ++i) {
                if (s[i] == cur) count++;
                else {
                    tmp += (count + '0');
                    tmp += cur;
                    cur = s[i];
                    count = 1;
                }
            }
            tmp += (count + '0');
            tmp += cur;
            s = tmp;
            nth++;
        }
        return s;
    }
};
