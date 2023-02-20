class Solution {
public:
    int alternateDigitSum(int n) {
        string str = to_string(n);
        bool sign = true;
        int ans = 0;
        
        for(char ch: str){
            ans += (ch-'0') * (sign?1:-1);
            sign = !sign;
        }

        return ans;
    }
};
