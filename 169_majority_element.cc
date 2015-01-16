class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> m;
        for (int i = 0; i < num.size(); ++i) {
            if (m.find(num[i]) == m.end()) m[num[i]] = 1;
            else m[num[i]]++;
        }
        unordered_map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > num.size() / 2) return it->first;
        }
    }
};
