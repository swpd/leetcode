class Solution {
public:
    static int cmp(const string a, const string b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int> &num) {
        string ans;
        vector<string> s;
        for (vector<int>::size_type i = 0; i < num.size(); ++i) s.push_back(std::to_string(num[i]));
        sort(s.begin(), s.end(), cmp);
        if (s[0] == "0") return "0";
        for (vector<int>::size_type i = 0; i < s.size(); ++i) ans += s[i];
        return ans;
    }
};
