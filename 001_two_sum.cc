class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        int len = numbers.size();
        for (int i = 0; i < len; ++i) m[numbers[i]] = i;
        for (int i = 0; i < len; ++i) {
            unordered_map<int, int>::iterator it = m.find(target - numbers[i]);
            if (it != m.end() && it->second != i) {
                vector<int> ans;
                ans.push_back(i + 1);
                ans.push_back(it->second + 1);
                return ans;
            }
        }
    }
};
