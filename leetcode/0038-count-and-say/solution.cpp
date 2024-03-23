class Solution {
public:
    string say(string str) {
        string ans = "";
        
        char cur = str[0];
        int count = 1;
        for (int i = 1; i < str.size(); i++) {
            char ch = str[i];
            if (ch == cur) {
                count++;
            } else {
                ans += to_string(count);
                ans += cur;

                cur = ch;
                count = 1;
            }
        }
        ans += to_string(count);
        ans += cur;

        return ans;
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            return say(countAndSay(n - 1));
        }
    }
};
