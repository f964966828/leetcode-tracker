class Solution {
public:
    int maxSubstrings(string word) {
        int ans = 0;
        vector<int> prev(26, -1);
        for (int i = 0; i < word.size(); i++) {
            int val = word[i] - 'a';
            if (prev[val] != -1 && i - prev[val] >= 3) {
                ans++;
                for (int i = 0; i < 26; i++) prev[i] = -1;
            } else if (prev[val] == -1) {
                prev[val] = i;
            }
        }
        return ans;
    }
};
