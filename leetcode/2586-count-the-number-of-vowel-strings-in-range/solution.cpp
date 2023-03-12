class Solution {
public:
    bool check(char ch){
        string target = "aeiou";
        for(char t: target)
            if(ch == t) return true;
                
        return false;
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++)
            if(check(words[i][0]) && check(words[i][words[i].size()-1]))
                ans++;
        
        return ans;
    }
};
