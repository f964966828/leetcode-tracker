class Solution {
public:
    bool notContainZero(int num) {
        while (num) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (notContainZero(i) && notContainZero(j)) {
                return {i, j};
            }
        }
        return {-1, -1};
    }
};
