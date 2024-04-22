class Solution {
public:
    bool check(vector<string>& deadends, string now) {
        for (string &deadend: deadends) {
            if (deadend == now) return false;
        }
        return true;
    }

    int openLock(vector<string>& deadends, string target) {
        if (!check(deadends, "0000")) return -1;

        vector<int> visited(10000);
        vector<string> bfs(1, "0000");

        int ans = 0;
        while (!bfs.empty()) {
            vector<string> new_bfs;
            for (string &now : bfs) {
                if (now == target) return ans;
                visited[stoi(now)] = 1;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        string next = now;
                        next[i] = (next[i] - '0' + (j ? 1 : -1) + 10) % 10 + '0';
                        if (!visited[stoi(next)] && check(deadends, next)) {
                            visited[stoi(next)] = 1;
                            new_bfs.push_back(next);
                        }
                    }
                }
            }
            ans++;
            bfs = new_bfs;
        }
        return -1;
    }
};
