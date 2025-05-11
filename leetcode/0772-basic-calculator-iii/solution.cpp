using Var = std::variant<int, char>;

class Solution {
public:
    string removeBlank(string &s) {
        string ns;
        for (char &ch : s) {
            if (ch != ' ') ns.push_back(ch);
        }
        return ns;
    }

    vector<Var> stringToInfix(string &s) {
        vector<Var> infix;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = 10 * num + (s[++i] - '0');
                }
                infix.push_back(num);
            } else {
                infix.push_back(s[i]);
            }
        }
        return infix;
    }

    void append(vector<Var> &postfix, stack<char> &stk) {
        postfix.push_back(stk.top());
        stk.pop();
    }

    int priority(char &op) { 
        switch(op) { 
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            default:            return 0;
        } 
    } 

    vector<Var> infixToPostfix(vector<Var> &infix) {
        vector<Var> postfix;
        stack<char> stk;
        for (auto &e : infix) {
            if (holds_alternative<int>(e)) {
                postfix.push_back(e);
            } else {
                char op = get<char>(e);
                if (op == ')') {
                    while (stk.top() != '(') append(postfix, stk);
                    stk.pop();
                } else if (op == '(') {
                    stk.push(op);
                } else {
                    while (!stk.empty() && priority(stk.top()) >= priority(op)) append(postfix, stk);
                    stk.push(op);
                }
            }
        }
        while (!stk.empty()) append(postfix, stk);
        return postfix;
    }

    int evalPostfix(vector<Var> &postfix) {
        stack<int> stk;
        for (auto &e : postfix) {
            if (holds_alternative<int>(e)) {
                stk.push(get<int>(e));
            } else {
                char op = get<char>(e);
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (op == '+') stk.push(a + b);
                else if (op == '-') stk.push(a - b);
                else if (op == '*') stk.push(a * b);
                else if (op == '/') stk.push(a / b);
            }
        }
        return stk.top();
    }

    int calculate(string s) {
        s = removeBlank(s);
        vector<Var> infix = stringToInfix(s);
        vector<Var> postfix = infixToPostfix(infix);
        int ans = evalPostfix(postfix);
        return ans;
    }
};
