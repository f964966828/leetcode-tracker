class Solution {
public:
    string findKthString(int n) {
        if (n == 1) {
            return "0";
        } else {
            string prev = findKthString(n-1);
            string cur = prev + '1';
            for (int i = 0; i < prev.size(); i++) {
                char ch = prev[prev.size() - 1 - i];
                cur += (ch == '0' ? '1' : '0');
            }
            return cur;
        }
    }

    char findKthBit(int n, int k) {
        string str = findKthString(n);
        return str[k-1];
    }
};
