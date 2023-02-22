class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int out = 0;
        for(int i=0; i<max(a.length(), b.length()); i++){
            int n1 = (i<a.length() ? a[i]-'0' : 0);
            int n2 = (i<b.length() ? b[i]-'0' : 0);
            ans += (n1+n2+out)%2 + '0';
            out = (n1+n2+out)/2;
        }

        if(out) ans += '1';
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};
