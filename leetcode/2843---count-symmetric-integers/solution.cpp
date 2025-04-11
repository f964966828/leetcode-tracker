class Solution {
public:

    bool symmetric(int num) {
        string str = to_string(num);
        if (str.size() % 2) return false;

        int l_sum = 0, r_sum = 0;
        for (int i = 0; i < str.size() / 2; i++) l_sum += str[i] - '0';
        for (int i = str.size() / 2; i < str.size(); i++) r_sum += str[i] - '0';

        return l_sum == r_sum;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            if (symmetric(i)) ans++;
        }
        return ans;
    }
};
