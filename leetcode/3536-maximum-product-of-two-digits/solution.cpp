class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        while (n) {
            vec.push_back(n % 10);
            n /= 10;
        }

        int ans = 0;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                ans = max(ans, vec[i] * vec[j]);
            }
        }

        return ans;
    }
};
