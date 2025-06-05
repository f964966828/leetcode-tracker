class Solution {
public:
    vector<int> p;

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void Union(int x, int y){
        int g1 = find(x);
        int g2 = find(y);
        if (g1 > g2) p[g1] = g2;
        else if (g1 < g2) p[g2] = g1;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for (int i = 0; i < 26; i++) p.push_back(i);
        for (int i = 0; i < n; i++) {
            int n1 = s1[i] - 'a';
            int n2 = s2[i] - 'a';
            Union(n1, n2);
        }

        string ans;
        for (char &ch : baseStr) ans.push_back(find(ch - 'a') + 'a');
        return ans;
    }
};
