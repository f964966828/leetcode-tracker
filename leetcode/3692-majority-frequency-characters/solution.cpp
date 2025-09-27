class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        for (char & ch : s) freq[ch - 'a']++;

        unordered_map<int, string> ump;
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (freq[i]) ump[freq[i]] += ch;
        }

        string ans;
        int f = 0;
        for (auto & [key, val] : ump) {
            if (val.size() > ans.size() || (val.size() == ans.size() && key > f)) {
                ans = val;
                f = key;
            }
        }

        return ans;
    }
};
