class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        for (char & ch : s) total += (ch - 'a' + 1);

        int half = 0;
        for (char & ch : s) {
            half += (ch - 'a' + 1);
            if (half * 2 == total) return true;
        }

        return false;
    }
};
