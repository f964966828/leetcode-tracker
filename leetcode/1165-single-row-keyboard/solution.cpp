class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> mapping(26);
        for (int i = 0; i < 26; i++) {
            mapping[keyboard[i] - 'a'] = i;
        }

        int ans = mapping[word[0] - 'a'];
        for (int i = 0; i < word.size() - 1; i++) {
            ans += abs(mapping[word[i] - 'a'] - mapping[word[i + 1] - 'a']);
        }

        return ans;
    }
};
