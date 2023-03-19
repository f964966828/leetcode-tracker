class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> info(26);
        for(int i=0; i<s.size(); i++){
            info[s[i]-'a'].first++;
            info[s[i]-'a'].second = i;
        }

        int ans = INT_MAX;
        for(int i=0; i<26; i++){
            if(info[i].first == 1){
                ans = min(ans, info[i].second);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
