class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int value[26];
        for(int i=0; i<26; i++) value[i] = i+1;
        
        for(int i=0; i<chars.size(); i++){
            value[chars[i] - 'a'] = vals[i];
        }
        
        vector<int> psum(1);
        for(int i=0; i<s.size(); i++){
            int val = value[s[i] - 'a'];
            psum.push_back(psum[i] + val);
        }
        
        int mn = psum[0], ans = 0;
        for(int i=1; i<psum.size(); i++){
            ans = max(ans, psum[i] - mn);
            mn = min(mn, psum[i]);
        }
        
        return ans;
    }
};
