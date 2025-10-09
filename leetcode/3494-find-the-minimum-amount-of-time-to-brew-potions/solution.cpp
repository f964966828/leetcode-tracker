class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + skill[i] * mana[0];
        for (int i = 1; i < m; i++) {
            long long max_diff = 0;
            vector<long long> new_prefix(n + 1);
            for (int j = 0; j < n; j++) {
                new_prefix[j + 1] = new_prefix[j] + skill[j] * mana[i];
                max_diff = max(max_diff, prefix[j + 1] - new_prefix[j]);
            }
            for (auto & p : new_prefix) p += max_diff;
            prefix = new_prefix;
        }
        return prefix[n];
    }
};
