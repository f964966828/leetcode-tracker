class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> counts(n + 1), ans(n);
        for (int i = 0; i < n; i++) {
            if (i != 0) ans[i] = ans[i - 1];
            ans[i] += (counts[A[i]]++ < 0);
            ans[i] += (counts[B[i]]-- > 0);
        }
        return ans;
    }
};
