class Solution {
public:
    string parseTernary(string expression) {
        reverse(expression.begin(), expression.end());
        vector<char> stk;
        for (char &ch : expression) {
            stk.push_back(ch);
            if (stk.size() >= 5 && stk[stk.size() - 2] == '?') {
                char flag = stk.back();
                stk.pop_back(); 
                stk.pop_back();
                char a = stk.back(); 
                stk.pop_back(); 
                stk.pop_back();
                char b = stk.back(); 
                stk.pop_back();
                
                stk.push_back(flag == 'T' ? a : b);
            }
        }
        return string(1, stk[0]);

    }
};
