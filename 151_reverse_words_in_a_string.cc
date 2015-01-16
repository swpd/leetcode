class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        string ans;
        bool in_word = false;
        bool start = false;
        string curr;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (in_word) {
                    if (!start) {
                        ans = curr;
                        start = true;
                    } else ans = curr + " " + ans;
                    in_word = false;
                    curr = "";
                }
            } else {
                if (!in_word) in_word = true;
                curr += s[i];
            }
        }
        if (curr != "") {
            if (!start) ans = curr;
            else ans = curr + " " + ans;
        }
        s = ans;
    }
};
