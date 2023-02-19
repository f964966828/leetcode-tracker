class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;
        for(string s: strs) len = (len<s.length() ? len : s.length());
        
        string ans = "";
        for(int i=0; i<len; i++){
            char tok = strs[0][i];
            bool flag = true;
            for(string s: strs){
                if(s[i] != tok) flag = false;
            }

            if(flag)
                ans += tok;
            else
                break;    
        }

        return ans;
    }
};
