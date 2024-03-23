class Solution {
public:
    string removeVowels(string s) {
        string ns = "";
        for (char ch: s) {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                ns.push_back(ch);
            }
        }
        return ns;
    }
};
