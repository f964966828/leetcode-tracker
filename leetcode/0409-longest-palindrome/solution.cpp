class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(char ch: s) mp[ch]++;
        
        int ans = 0;
        for(auto e: mp){
            int t = e.second;
            if(t%2){
                ans += (t/2)*2;
                if(!(ans%2)) ans++;
            }else
                ans += e.second;
        }

        return ans;
    }
};
