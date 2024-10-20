class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> p_xor(n+1);
        for (int i = 0; i < n; i++) {
            p_xor[i+1] = p_xor[i] ^ arr[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    int a = p_xor[j] ^ p_xor[i];
                    int b = p_xor[k+1] ^ p_xor[j];
                    if (a == b) count++;
                }
            }
        }

        return count;
    }
};
