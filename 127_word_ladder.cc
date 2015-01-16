class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        int len = start.size();
        unordered_map<string, vector<string> > m;
        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
            for (int j = 0; j < len; ++j) {
                string str(*i);
                for (char k = 'a'; k <= 'z'; ++k) {
                    str[j] = k;
                    if (str != *i && dict.find(str) != dict.end()) m[*i].push_back(str);
                }
            }
        }
        unordered_set<string> visited;
        queue<string> q;
        queue<int> steps;
        q.push(start);
        steps.push(1);
        visited.insert(start);
        while (!q.empty()) {
            string front = q.front();
            int s = steps.front();
            if (front == end) return s;
            q.pop();
            steps.pop();
            int n = m[front].size();
            for (int i = 0; i < n; ++i) {
                if (visited.find(m[front][i]) == visited.end()) {
                    q.push(m[front][i]);
                    steps.push(s + 1);
                    visited.insert(m[front][i]);
                }
            }
        }
        return 0;
    }
};
