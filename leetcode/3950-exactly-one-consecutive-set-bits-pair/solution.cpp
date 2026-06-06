class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> binary;
        while (n) {
            binary.push_back(n % 2);
            n /= 2;
        }
        int count = 0;
        for (int i = 1; i < binary.size(); i++) {
            if (binary[i] == binary[i - 1] && binary[i] == 1) count++;
        }
        return count == 1;
    }
};
