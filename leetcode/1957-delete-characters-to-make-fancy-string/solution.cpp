class Solution {
public:
    string makeFancyString(string s) {
        char prev = ' ';
        int count = 0;
        
        string ans;
        for (char ch : s) {
            if (prev != ch) {
                prev = ch;
                count = 0;
            }
            if (++count <= 2) ans.push_back(ch);
        }

        return ans;
    }
};
