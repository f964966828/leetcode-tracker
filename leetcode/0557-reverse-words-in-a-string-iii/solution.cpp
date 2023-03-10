class Solution {
public:
    string reverseWords(string s) {
        int e=0;
        for(int i=0; i<=s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin()+e, s.begin()+i);
                e = i+1;
            }
        }
        return s;
    }
};
