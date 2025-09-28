class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int power = 0;
        while (n) {
            if (n % 10) ans.push_back(n % 10 * pow(10, power));
            n /= 10;
            power++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
