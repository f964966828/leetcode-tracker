class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> left_indices;
        vector<bool> valid(s.size(), true);
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_indices.push_back(i);
                count++;
            } else if (s[i] == ')') {
                if (count == 0) {
                    valid[i] = false;
                } else {
                    count--;
                }
            }
        }

        for (int i = 0; i < count; i++) {
            int index = left_indices[left_indices.size() - 1 - i];
            valid[index] = false;
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (valid[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};
