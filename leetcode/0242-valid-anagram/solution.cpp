class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);
        for(char ch: s) count[ch-'a']++;
        for(char ch: t) count[ch-'a']--;

        for(int n: count)
            if(n != 0) return false;

        return true;
    }
};
