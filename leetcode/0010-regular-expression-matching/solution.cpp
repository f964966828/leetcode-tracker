class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<vector<int>>> roads;
        vector<vector<int>> road(27, vector<int>(1, 0));
        roads.push_back(road); // empty state
        for (int i = 0; i < p.size(); i++) {
            bool next_star = (i + 1 < p.size() && p[i + 1] == '*');
            
            int index = roads.size();
            road.clear();
            road.resize(27, vector<int>(1, 0));
            if (p[i] == '.') {
                for (int j = 1; j <= 26; j++) {
                    road[j].push_back(index + 1);
                    if (next_star) road[j].push_back(index);
                }
            } else {
                road[p[i] - 'a' + 1].push_back(index + 1);
                if (next_star) road[p[i] - 'a' + 1].push_back(index);
            }

            if (next_star) {
                road[0].push_back(index + 1); // skip state
            }
            while (i + 1 < p.size() && p[i + 1] == '*') {
                i++;
            }
            roads.push_back(road);
        }
        road.clear();
        road.resize(27, vector<int>(1, 0));
        roads.push_back(road); // end state

        set<int> bfs;
        bfs.insert(1); // init state
        for (char ch: s) {
            // expand skip states
            for (int from: bfs) {
                while (from < roads.size() && roads[from][0].size() != 1) {
                    bfs.insert(from + 1);
                    from++;
                }
            }

            set<int> new_bfs;
            // next state
            for (int from: bfs) {
                for (int to: roads[from][ch - 'a' + 1]) {
                    new_bfs.insert(to);
                }
            }
            bfs = new_bfs;
        }

        // expand skip states
        for (int from: bfs) {
            while (from < roads.size() && roads[from][0].size() != 1) {
                bfs.insert(from + 1);
                from++;
            }
        }

        for (int from: bfs) {
            if (from == roads.size() - 1) {
                return true;
            }
        }

        return false;
    }
};
