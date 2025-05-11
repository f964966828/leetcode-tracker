class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> counts(26);
        for (char &ch : s) {
            counts[ch - 'a']++;
        }

        sort(counts.begin(), counts.end());
        int count = 0, ans = 0;
        for (int i = 0; i < 26; i++) if (counts[i]) count++;
        for (int i = 0; i < 26; i++) {
            if (count > k && counts[i]) {
                count--;
                ans += counts[i];
            }
        }
        return ans;
    }
};
