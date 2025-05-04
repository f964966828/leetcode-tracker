class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 0, pos = 0, n = source.size(), m = target.size();
        bool modified = true;
        while (pos < m && modified) {
            modified = false;
            for (char &ch : source) {
                if (pos < m && ch == target[pos]) {
                    pos++;
                    modified = true;
                }
            }
            ans++;
        }
        return (pos == m ? ans : -1);
    }
};
