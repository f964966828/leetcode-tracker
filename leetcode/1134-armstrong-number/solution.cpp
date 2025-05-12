class Solution {
public:
    bool isArmstrong(int n) {
        int k = to_string(n).size();
        int sum = 0, temp = n;
        while (temp) {
            sum += pow(temp % 10, k);
            temp /= 10;
        }
        return sum == n;
    }
};
