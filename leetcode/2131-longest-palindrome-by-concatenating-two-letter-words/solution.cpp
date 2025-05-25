class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (string &word : words) {
            mp[word]++;
        }
        cout << endl;

        int pair = 0;
        bool middle = false;
        for (auto [key, value] : mp) {
            if (key[0] < key[1]) {
                string rev = key;
                swap(rev[0], rev[1]);
                if (mp.count(rev)) pair += min(value, mp[rev]);
            } else if (key[0] == key[1]) {
                pair += (value / 2);
                if (value % 2) middle = true;
            }
        }

        return 4 * pair + (middle ? 2 : 0);
    }
};
