class Solution {
public:
    double solve(int from, int to, vector<vector<double>> &matrix) {
        int n = matrix.size();
        vector<bool> visited(n, false);
        
        double ans = -1.0;
        stack<pair<int, double>> stk;
        stk.push({from, 1.0});        
        while (!stk.empty()) {
            int from = stk.top().first;
            double cost = stk.top().second;
            stk.pop();

            visited[from] = true;
            if (from == to) ans = cost;

            for (int i = 0; i < n; i++) {
                if (matrix[from][i] != 0.0 && !visited[i]) {
                    stk.push({i, cost * matrix[from][i]});
                }
            }
        }

        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> mp;
        for (auto equation : equations) {
            for (string var : equation) {
                if (mp.find(var) == mp.end()) mp[var] = mp.size();
            }
        }

        int n = mp.size();
        vector<vector<double>> matrix(n, vector<double>(n, 0.0));
        for (int i = 0; i < equations.size(); i++) {
            int from = mp[equations[i][0]];
            int to = mp[equations[i][1]];
            matrix[from][to] = values[i];
            matrix[to][from] = 1 / values[i];
        }

        vector<double> answer;
        for (auto query : queries) {
            if (mp.find(query[0]) == mp.end() || mp.find(query[1]) == mp.end()) {
                answer.push_back(-1.0);
            } else {
                int from = mp[query[0]];
                int to = mp[query[1]];
                answer.push_back(solve(from, to, matrix));
            }
        }
        return answer;
    }
};
