class Solution {
public:
    bool valid(vector<int> &counts) {
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 1) return false;
        }
        return true;
    }

    int numKLenSubstrNoRepeats(string s, int k) {
        if (s.size() < k) return 0;

        vector<int> counts(26);
        for (int i = 0; i < k; i++) counts[s[i] - 'a']++;
        
        int ans = 0;
        if (valid(counts)) ans++;
        for (int i = k; i < s.size(); i++) {
            counts[s[i - k] - 'a']--;
            counts[s[i] - 'a']++;
            if (valid(counts)) ans++;
        }

        return ans;
    }
};
