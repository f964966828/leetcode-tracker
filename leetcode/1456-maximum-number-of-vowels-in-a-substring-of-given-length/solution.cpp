char vowels[] = "aeiou";

class Solution {
public:
    bool is_vowel(char ch) {
        for (char vowel : vowels) {
            if (ch == vowel) return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int num = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowel(s[i])) num++;
        }

        int ans = num;
        for (int i = k; i < s.size(); i++) {
            if (is_vowel(s[i])) num++;
            if (is_vowel(s[i - k])) num--;
            ans = max(ans, num);
        }

        return ans;
    }
};
