class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch == '('){
                st.push(ch);
            }else if(ch == '['){
                st.push(ch);
            }else if(ch == '{'){
                st.push(ch);
            }else if(ch == ')'){
                if(st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            }else if(ch == ']'){
                if(st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
            }else if(ch == '}'){
                if(st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};
