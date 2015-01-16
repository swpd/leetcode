class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int remain = 0;
        int need = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            remain += (gas[i] - cost[i]);
            if (remain < 0) {
                need -= remain;
                remain = 0;
                idx = i + 1;
            }
        }
        if (remain >= need) return idx;
        else return -1;
    }
};
