class Solution {
public:
    void build_ans(vector<vector<string> > &ans, unordered_map<string, vector<string> > &parent, vector<string> &v, string start) {
        if (v[v.size() - 1] == start) {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        vector<string> p = parent[v[v.size() - 1]];
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            v.push_back(p[i]);
            build_ans(ans, parent, v, start);
            v.pop_back();
        }
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ans;
        dict.insert(start);
        dict.insert(end);
        int len = start.size();
        queue<string> q;
        unordered_map<string, int> steps;
        unordered_set<string> visited;
        q.push(start);
        steps[start] = 1;
        visited.insert(start);
        int found_step = 0;
        unordered_map<string, vector<string> > parent;
        // BFS
        while (!q.empty()) {
            string front = q.front();
            q.pop();
            int s = steps[front];
            if ((found_step > 0) && (s == found_step + 1)) break;
            for (int i = 0; i < len; ++i) {
                string str(front);
                for (char j = 'a'; j <= 'z'; ++j) {
                    str[i] = j;
                    if (dict.find(str) != dict.end()) {
                        if (visited.find(str) == visited.end()) {
                            q.push(str);
                            steps[str] = s + 1;
                            visited.insert(str);
                            parent[str].push_back(front);
                            if (str == end) found_step = s + 1;
                        } else {
                            if (s + 1 == steps[str]) parent[str].push_back(front);
                        }
                    }
                }
            }
        }
        // DFS
        vector<string> v;
        v.push_back(end);
        build_ans(ans, parent, v, start);
        return ans;
    }
};
