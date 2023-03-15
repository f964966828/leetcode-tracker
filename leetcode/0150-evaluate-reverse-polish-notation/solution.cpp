class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(string tok: tokens){
            if(tok=="+" || tok=="-" || tok=="*" || tok=="/"){
                int n2 = stoi(s.top()); s.pop();
                int n1 = stoi(s.top()); s.pop();

                int ret;
                if(tok == "+")
                    ret = n1+n2;
                else if(tok == "-")
                    ret = n1-n2;
                else if(tok == "*")
                    ret = n1*n2;
                else if(tok == "/")
                    ret = n1/n2;
                s.push(to_string(ret));
            }else{
                s.push(tok);
            }
        }
        return stoi(s.top());
    }
};
