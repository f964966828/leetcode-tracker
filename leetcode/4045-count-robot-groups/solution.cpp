class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> groups;
        int n = speed.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || position[i + 1] - position[i] > distance) {
                groups.push_back(speed[i]);
            } 
        }

        reverse(groups.begin(), groups.end());
        int ans = 0, cur = INT_MAX;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] <= cur) {
                cur = groups[i];
                ans++;   
            }
        }

        return ans;
    }
};
