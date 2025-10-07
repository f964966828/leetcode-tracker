class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zeros;
        map<int, int> rain_pos, pos_dry;
        
        int n = rains.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeros.insert(i);
            } else {
                if (rain_pos.find(rains[i]) == rain_pos.end()) {
                    rain_pos[rains[i]] = i;
                } else {
                    int pos = rain_pos[rains[i]];
                    auto iter = zeros.upper_bound(pos);
                    if (iter == zeros.end()) return ans;
                    else {
                        pos_dry[*iter] = rains[i];
                        zeros.erase(iter);
                        rain_pos[rains[i]] = i;
                    }
                }
            }
        }

        ans.resize(n, -1);
        for (auto & [pos, dry] : pos_dry) ans[pos] = dry;
        for (auto & pos : zeros) ans[pos] = 1; //arbitrary;

        return ans;
    }
};
