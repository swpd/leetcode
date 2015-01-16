class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2) return 0;
        while (!version1.empty() && !version2.empty()) {
            string::size_type n1 = version1.find(".");
            int num1 = atoi(version1.substr(0, n1).c_str());
            string::size_type n2 = version2.find(".");
            int num2 = atoi(version2.substr(0, n2).c_str());
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            version1 = n1 == string::npos ? "" : version1.substr(n1 + 1);
            version2 = n2 == string::npos ? "" : version2.substr(n2 + 1);
        }
        string empty = version1.empty() ? version1 : version2;
        string non_empty = version1.empty() ? version2 : version1;
        while (!non_empty.empty()) {
            string::size_type n = non_empty.find(".");
            int num = atoi(non_empty.substr(0, n).c_str());
            if (num == 0) non_empty = n ==  string::npos ? "" : non_empty.substr(n + 1);
            else break;
        }
        if (non_empty.empty()) return 0;
        if (version1.empty() && !version2.empty()) return -1;
        if (!version1.empty() && version2.empty()) return 1;
    }
};
