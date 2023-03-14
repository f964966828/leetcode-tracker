class Solution {
public:
    bool check(vector<int> freq){
        for(int n: freq)
            if(n) return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26), ans;
        for(char ch: p) freq[ch-'a']++;

        int j=0;
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']--;
            if(i >= p.size())
                freq[s[j++]-'a']++;
            if(check(freq))
                ans.push_back(j);
        }
        return ans;
    }
};
