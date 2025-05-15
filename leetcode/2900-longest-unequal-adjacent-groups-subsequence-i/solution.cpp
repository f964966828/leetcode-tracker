class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int cur = -1;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != cur) {
                ans.push_back(words[i]);
            } else if (ans.back().size() < words[i].size()) {
                ans.pop_back();
                ans.push_back(words[i]);
            }
            cur = groups[i];
        }
        return ans;
    }
};
