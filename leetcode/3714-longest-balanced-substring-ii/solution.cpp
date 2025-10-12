class Solution {
public:
    int findThreeComponent(string s) {
        int ans = 0;
        vector<int> count(3);
        map<vector<int>, int> mp;
        mp[count] = -1;
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            if (count[0] && count[1] && count[2]) {
                count[0]--; count[1]--; count[2]--;    
            }
            
            if (mp.find(count) != mp.end()) ans = max(ans, i - mp[count]);
            else mp[count] = i;
        }
        return ans;
    }

    int findTwoComponent(string s) {
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                pair<int, int> count = {0, 0};
                map<pair<int, int>, int> mp;
                mp[count] = -1;
                for (int k = 0; k < s.size(); k++) {
                    int val = s[k] - 'a';
                    if (val == i) {
                        count.first++;
                    } else if (val == j) {
                        count.second++;
                    } else {
                        count.first = count.second = 0;
                        mp.clear();
                        mp[count] = k;
                        continue;
                    }

                    if (count.first && count.second) {
                        count.first--; count.second--;
                    }

                    if (mp.find(count) != mp.end()) {
                        ans = max(ans, k - mp[count]);
                    } else mp[count] = k;
                }
            }
        }
        return ans;
    }

    int findOneComponent(string s) {
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            int count = 0;
            for (char & ch : s) {
                if (ch - 'a' == i) count++;
                else count = 0;
                ans = max(ans, count);
            }
        }
        return ans;
    }
    
    int longestBalanced(string s) {
        int ans = 0;
        ans = max(ans, findThreeComponent(s));
        ans = max(ans, findTwoComponent(s));
        ans = max(ans, findOneComponent(s));
        return ans;
    }
};
