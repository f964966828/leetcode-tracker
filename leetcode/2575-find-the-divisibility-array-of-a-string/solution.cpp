class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        
        long long num = 0;
        for(char ch: word){
            num *= 10;
            num += (ch-'0');
            num %= m;
            ans.push_back(num ? 0 : 1);
        }
        
        return ans;
    }
};
