class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<bool> flags(26, false);
        int total = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            total += (flags[idx] ? -1 : 1);
            flags[idx] = !flags[idx];
        }
        return total <= 1;
    }
};
