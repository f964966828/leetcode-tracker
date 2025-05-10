class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiou";
        for (char &vowel : vowels) {
            if (ch == vowel) return true;
        }
        return false;
    }
    
    int maxFreqSum(string s) {
        vector<int> counts(26);
        int vowelMax = 0, consonantMax = 0;
        for (char &ch : s) {
            int val = ch - 'a';
            counts[val]++;
            if (isVowel(ch)) {
                vowelMax = max(vowelMax, counts[val]);
            } else {
                consonantMax = max(consonantMax, counts[val]);
            }
        }
        return vowelMax + consonantMax;
    }
};
