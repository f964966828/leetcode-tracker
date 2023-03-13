class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        
        for(char ch: s){
            if(ch == '#' && !st1.empty())
                st1.pop();
            else if(ch != '#')
                st1.push(ch);
        }

        for(char ch: t){
            if(ch == '#' && !st2.empty())
                st2.pop();
            else if(ch != '#')
                st2.push(ch);
        }

        string ret1, ret2;
        while(!st1.empty()){
            ret1 += st1.top();
            st1.pop();
        }

        while(!st2.empty()){
            ret2 += st2.top();
            st2.pop();
        }

        cout << ret1 << endl << ret2 << endl;

        return (ret1 == ret2);
    }
};
