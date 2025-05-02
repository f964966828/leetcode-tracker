class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, -1), right(n, -1);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') right[i] = i;
            else if (dominoes[i] == '.' && i != 0) right[i] = right[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') left[i] = i;
            else if (dominoes[i] == '.' && i != n - 1) left[i] = left[i + 1];
        }

        string ans;
        for (int i = 0; i < n; i++) {
            int l = (left[i] == -1 ? INT_MAX : left[i] - i);
            int r = (right[i] == -1 ? INT_MAX : i - right[i]);
            if (l < r) {
                ans.push_back('L');
            } else if (l > r) {
                ans.push_back('R');
            } else {
                ans.push_back('.');
            }
        }

        return ans;
    }
};
