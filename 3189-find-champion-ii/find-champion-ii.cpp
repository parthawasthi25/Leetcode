class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> lookup(n);
        for (const auto& e : edges) {
            lookup[e[1]] = true;
        }
        int result = -1;
        for (int u = 0; u < n; ++u) {
            if (lookup[u]) {
                continue;
            }
            if (result != -1) {
                return -1;
            }
            result = u;
        }
        return result;
    }
};