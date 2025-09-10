class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>> learn(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (auto &l : languages[i]) learn[i][l - 1] = true; 
        }
        
        vector<vector<int>> unreach;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool reach = false;
            for (int i = 0; i < n; i++) {
                if (learn[u][i] && learn[v][i]) reach = true;
            }
            if (!reach) unreach.push_back(f);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> indices;
            for (auto &f : unreach) {
                int u = f[0] - 1, v = f[1] - 1;
                if (!learn[u][i]) learn[u][i] = true, indices.push_back(u);
                if (!learn[v][i]) learn[v][i] = true, indices.push_back(v);
            }
            ans = min(ans, (int) indices.size());
            for (auto &idx : indices) learn[idx][i] = false;
        }

        return ans;
    }
};
