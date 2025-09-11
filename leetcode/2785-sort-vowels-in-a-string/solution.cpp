class Solution {
public:
    string vowels = "aeiouAEIOU";

    bool isVowel(char ch) {
        for (char &vowel : vowels) {
            if (ch == vowel) return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> values;
        vector<int> indices;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                values.push_back(s[i]);
                indices.push_back(i);
            }
        }
        sort(values.begin(), values.end());

        for (int i = 0; i < values.size(); i++) {
            s[indices[i]] = values[i];
        }
        return s;
    }
};
