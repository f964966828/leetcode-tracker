class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> mp;
        for (auto seats : reservedSeats) {
            int x = seats[0], y = seats[1];
            mp[x].push_back(y);
        }

        int ans = (n - mp.size()) * 2;
        for (auto e : mp) {
            vector<bool> flag(11, true);
            for (auto i : e.second) flag[i] = false;
            bool left = flag[2] && flag[3] && flag[4] && flag[5];
            bool mid = flag[4] && flag[5] && flag[6] && flag[7];
            bool right = flag[6] && flag[7] && flag[8] && flag[9];
            if (left) ans++;
            if (right) ans++;
            if (!left && !right && mid) ans++;
        }
        return ans;
    }
};
