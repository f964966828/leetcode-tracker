class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i = 0, cnt = 0, target = 0, ans = 0;
        
        vector<int> seq;
        for(int i=0; i<s.size(); i++){
            if(s[i] == target + '0'){
                cnt++;
            }
            if(s[i] != target + '0'){
                seq.push_back(cnt);
                target = !target;
                cnt = 1;
            }
        }
        seq.push_back(cnt);
        
        for(int i=1; i<seq.size(); i+=2){
            ans = max(ans, min(seq[i-1], seq[i]) * 2);
        }
        
        return ans;
    }
};
