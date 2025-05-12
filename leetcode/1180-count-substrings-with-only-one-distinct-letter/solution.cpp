class Solution {
public:
    int countLetters(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int count = 1;
            while (i + 1 < s.size() && s[i + 1] == s[i]) i++, count++;
            ans += count * (count + 1) / 2;
        }
        return ans;
    }
};
