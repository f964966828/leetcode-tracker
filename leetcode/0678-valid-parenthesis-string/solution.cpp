class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (auto ch: s) {
            low += (ch == '(' ? 1 : -1);
            high += (ch != ')' ? 1 : -1);
            if (high < 0) {
                return false;
            }
            low = max(low, 0);
        }
        return (low == 0);
    }
};
