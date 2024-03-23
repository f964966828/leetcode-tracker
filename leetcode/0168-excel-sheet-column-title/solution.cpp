class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber) {
            ans = char((columnNumber - 1) % 26 + 'A') + ans;
            if (columnNumber % 26 == 0) {
                columnNumber /= 26;
                columnNumber--;
            } else {
                columnNumber /= 26;
            }
        }
        return ans;
    }
};
