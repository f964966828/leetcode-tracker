char vowels[] = "aeiouAEIOU";

class Solution {
public:
    bool is_vowel(char ch) {
        for (char vowel : vowels) {
            if (ch == vowel) return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        vector<pair<int, char>> info;
        for (int i = 0; i < s.size(); i++) {
            if (is_vowel(s[i])) info.push_back({i, s[i]});
        }
        for (int i = 0; i < info.size(); i++) {
            s[info[info.size() - 1 - i].first] = info[i].second;
        }
        return s;
    }
};
