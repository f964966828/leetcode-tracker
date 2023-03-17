class Solution {
public:
    string decode(string s, int n){
        cout << s << " " << n << endl;
        string num, text, str, ans;
        int count = 0;
        for(char ch: s){
            if(ch == ']'){
                count--;
                if(!count){
                    ans += decode(str, stoi(num));
                    num.clear();
                    str.clear();
                }
            }

            if(count)
                str += ch;
            else if(ch <= '9' && ch >= '0')
                num += ch;
            else if(ch != '[' && ch != ']')
                text += ch;

            if(ch == '['){
                if(!count){
                    ans += text;
                    text.clear();
                }
                count++;
            }
        }
        ans += text;
        
        string ret;
        while(n--) 
            ret += ans;

        return ret;
    }
    string decodeString(string s) {
        return decode(s, 1);
    }
};
