using Param = std::pair<int, std::vector<string>>;

class Solution {
public:
    vector<string> stringToInfix(string &s) {
        vector<string> infix;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '(' || s[i] == ')') {
                infix.push_back(string(1, s[i]));
            } else {
                string tok(1, s[i]);
                while (i + 1 < s.size() && s[i + 1] != ' ' && s[i + 1] != '(' && s[i + 1] != ')') tok.push_back(s[++i]);
                infix.push_back(tok);
            }
        }
        return infix;
    }

    void append(vector<string> &postfix, stack<string> &stk) {
        postfix.push_back(stk.top());
        stk.pop();
    }

    int priority(string &tok) { 
        switch (tok[0]) { 
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            default:            return 0;
        } 
    } 

    bool isOperator(string tok) {
        string operators = "+-*()";
        if (tok.size() != 1) return false;
        for (char &op : operators) if (tok[0] == op) return true;
        return false;
    }

    vector<string> infixToPostfix(vector<string> &infix) {
        vector<string> postfix;
        stack<string> stk;
        for (auto &tok : infix) {
            if (isOperator(tok)) {
                if (tok == ")") {
                    while (stk.top() != "(") append(postfix, stk);
                    stk.pop();
                } else if (tok == "(") {
                    stk.push(tok);
                } else {
                    while (!stk.empty() && priority(stk.top()) >= priority(tok)) append(postfix, stk);
                    stk.push(tok);
                }
            } else {
                postfix.push_back(tok);
            }
        }
        while (!stk.empty()) append(postfix, stk);
        return postfix;
    }

    vector<Param> merge(vector<Param> &params) {
        vector<Param> merged;
        sort(params.begin(), params.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        for (int i = 0; i < params.size(); i++) {
            int coef = params[i].first;
            while (i + 1 < params.size() && params[i + 1].second == params[i].second) coef += params[++i].first;
            if (coef) merged.push_back({coef, params[i].second});
        }
        return merged;
    }

    vector<Param> add(vector<Param> &a, vector<Param> &b) {
        vector<Param> result;
        for (auto &p : a) result.push_back(p);
        for (auto &p : b) result.push_back(p);
        return merge(result);
    }

    vector<Param> sub(vector<Param> &a, vector<Param> &b) {
        for (auto &p : b) p.first = -1 * p.first;
        return add(a, b);
    }

    vector<Param> mul(vector<Param> &a, vector<Param> &b) {
        vector<Param> result;
        for (auto &p1 : a) {
            for (auto &p2 : b) {
                Param p = {p1.first * p2.first, {}};
                for (string &var : p1.second) p.second.push_back(var);
                for (string &var : p2.second) p.second.push_back(var);
                sort(p.second.begin(), p.second.end());
                result.push_back(p);
            }
        }
        return merge(result);
    }

    vector<string> evalPostfix(vector<string> &postfix, map<string, int> &varMap) {
        stack<vector<Param>> stk;
        for (auto &tok : postfix) {
            if (isOperator(tok)) {
                char op = tok[0];
                vector<Param> b = stk.top(); stk.pop();
                vector<Param> a = stk.top(); stk.pop();
                if (op == '+') {
                    stk.push(add(a, b));
                } else if (op == '-') {
                    stk.push(sub(a, b));
                } else if (op == '*') {
                    stk.push(mul(a, b));
                }
            } else {
                Param p;
                if (isdigit(tok[0])) {
                    p = {stoi(tok), {}};
                } else if (varMap.find(tok) != varMap.end()) {
                    p = {varMap[tok], {}};
                } else {
                    p = {1, {tok}};
                }
                stk.push(vector<Param>(1, p));
            }
        }

        vector<Param> params = merge(stk.top());
        sort(params.begin(), params.end(), [](const auto& a, const auto& b) {
            if (a.second.size() != b.second.size()) {
                return a.second.size() > b.second.size();
            } else {
                return a.second < b.second;
            }
        });

        vector<string> results;
        for (Param &p : params) {
            string str;
            str += to_string(p.first);
            for (string &var : p.second) {
                str += "*" + var;
            }
            results.push_back(str);
        }

        return results;
    }

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        map<string, int> varMap;
        for (int i = 0; i < evalvars.size(); i++) {
            varMap[evalvars[i]] = evalints[i];
        }

        vector<string> infix = stringToInfix(expression);
        vector<string> postfix = infixToPostfix(infix);
        vector<string> results = evalPostfix(postfix, varMap);

        return results;
    }
};
