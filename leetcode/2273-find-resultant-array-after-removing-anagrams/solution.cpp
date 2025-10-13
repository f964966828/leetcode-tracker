class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int> prev(26);
        vector<string> ans;
        for (auto & word : words) {
            vector<int> count(26);
            for (char & ch : word) count[ch - 'a']++;
            if (count != prev) ans.push_back(word);
            prev = count;
        }
        return ans;
    }
};
