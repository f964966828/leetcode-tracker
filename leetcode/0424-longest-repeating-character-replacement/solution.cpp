class Solution {
public:
    int getCount(vector<int>& freq){
        int mx = 0, sum = 0;
        for(int n: freq){
            mx = max(mx, n);
            sum += n;
        }
        return sum - mx;
    }
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int l=0, ans = 0;
        for(int r=0; r<s.size(); r++){
            freq[s[r]-'A']++;
            if(getCount(freq) > k)
                freq[s[l++]-'A']--;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
