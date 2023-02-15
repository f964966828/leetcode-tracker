class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size() == 1) return s;

        string ans = "";
        int mx = 0;
        for(int i=0; i<s.size()-1; i++){
            int c = 0;
            while(i-c>=0 && i+c<s.size() && s[i-c]==s[i+c]) c++;
            c--;
            if(2*c+1 > mx){
                mx = 2*c+1;
                ans = "";
                for(int j=i-c; j<=i+c; j++) ans += s[j];
            }
            
            if(s[i+1]!=s[i]) continue;
            c = 0;
            while(i-c>=0 && i+c+1<s.size() && s[i-c]==s[i+c+1]) c++;
            c--;
            if(2*c+2 > mx){
                mx = 2*c+2;
                ans = "";
                for(int j=i-c; j<=i+c+1; j++) ans += s[j];
            }
        }

        return ans;
    }
};
