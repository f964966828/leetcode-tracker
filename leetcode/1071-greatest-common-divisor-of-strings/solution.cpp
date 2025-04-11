class Solution {
public:
    bool dividable(string str, string div) {
        if (str.size() % div.size() != 0) return false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != div[i % div.size()]) {
                return false;
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string gcd = "", div = "";
        for (int i = 0; i < min(str1.size(), str2.size()); i++) {
            if (str1[i] == str2[i]) {
                div += str1[i];
                if (dividable(str1, div) && dividable(str2, div)) {
                    gcd = div;
                }
            } else {
                break;
            }
        }
        return gcd;
    }
};
