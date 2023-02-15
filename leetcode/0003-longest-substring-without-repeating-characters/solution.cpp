class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> mp;
        int ans = 0, st = 0;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                ans = max(ans, i-st);
                st = max(st, mp[s[i]]+1);
            }
            mp[s[i]] = i;
        }
        ans = max(ans, (int)s.length()-st);

        return ans;
    }
};
