class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int n = word.size(), mx = 0;
        vector<pair<int, int>> bfs;
        for (int i = 0; i < n; i++) mx = max(mx, word[i] - 0);
        for (int i = 0; i < n; i++) if (word[i] == mx) bfs.push_back({i, 1});

        vector<bool> visited(n, false);
        while (bfs.size() != 1) {
            mx = 0;
            for (auto &[index, length] : bfs) if (index + 1 < n) mx = max(mx, word[index + 1] - 0);
            
            int last_index = -1, last_length = -1;
            vector<pair<int, int>> new_bfs;
            for (auto &[index, length] : bfs) {
                if (visited[index - length + 1]) continue;
                if (index == n - 1 || length == n - numFriends + 1) {
                    last_index = index;
                    last_length = length;
                    continue;
                } else if (word[index + 1] == mx) {
                    new_bfs.push_back({index + 1, length + 1});
                    visited[index + 1] = true;
                }
            }

            if (new_bfs.empty()) new_bfs.push_back({last_index, last_length});
            bfs = new_bfs;
        }

        string ans = "";
        int index = bfs[0].first - bfs[0].second + 1;
        for (int i = 0; i < n - numFriends + 1; i++) {
            if (index + i < n) ans.push_back(word[index + i]);
        }
        return ans;
    }
};
