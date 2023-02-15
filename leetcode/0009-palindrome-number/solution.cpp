class Solution {
public:
    bool isPalindrome(int x) {
        string str1 = to_string(x);

        string str2 = str1;
        reverse(str2.begin(), str2.end());

        return str1 == str2;
    }
};
