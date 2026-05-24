class Solution {
public:
    int passwordStrength(string password) {
        set<char> s;
        for (char ch : password) s.insert(ch);

        int strength = 0;
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                strength += 1;
            } else if (ch >= 'A' && ch <= 'Z') {
                strength += 2;
            } else if (ch >= '0' && ch <= '9') {
                strength += 3;
            } else {
                strength += 5;
            }
        }
        return strength;
    }
};
