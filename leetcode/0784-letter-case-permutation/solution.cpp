class Solution {
public:    
    void solve(int idx, string s, vector<string> &ans) {
        if(idx >= s.size()){
            ans.push_back(s);
            return;
        }

        solve(idx+1, s, ans);
        if(s[idx] >= 'a' && s[idx] <= 'z'){
            s[idx] += ('A'-'a');
            solve(idx+1, s, ans);
            s[idx] -= ('A'-'a');
        }else if(s[idx] >= 'A' && s[idx] <= 'Z'){
            s[idx] -= ('A'-'a');
            solve(idx+1, s, ans);
            s[idx] += ('A'-'a');
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(0, s, ans);
        return ans; 
    }
};
