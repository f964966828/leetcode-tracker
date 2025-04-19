class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1, mp2;
        for (char ch : word1) mp1[ch]++;
        for (char ch : word2) mp2[ch]++;

        if (mp1.size() != mp2.size()) return false;
        for (auto e : mp1) {
            if (mp2.find(e.first) == mp2.end()) return false;
        }

        map<int, int> mpp1, mpp2;
        for (auto e : mp1) mpp1[e.second]++;
        for (auto e : mp2) mpp2[e.second]++;

        if (mpp1.size() != mpp2.size()) return false;
        for (auto e : mpp1) {
            if (e.second != mpp2[e.first]) return false;
        }
        return true;
    }
};
