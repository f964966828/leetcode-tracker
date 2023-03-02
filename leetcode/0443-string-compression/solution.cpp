class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0, cnt = 1;
        char ch = ' ';
        vector<char> vec;
        for(int i=0; i<chars.size(); i++){
            if(chars[i] == ch) cnt++;
            if(chars[i] != ch){
                if(ch != ' '){
                    vec.push_back(ch);
                    ans++;
                    if(cnt > 1)
                        for(char c: to_string(cnt)) vec.push_back(c), ans++;
                }
                ch = chars[i];
                cnt = 1;
            }
        }
        vec.push_back(ch);
        ans++;
        if(cnt > 1)
            for(char c: to_string(cnt)) vec.push_back(c), ans++;

        chars = vec;
        return ans;
    }
};
