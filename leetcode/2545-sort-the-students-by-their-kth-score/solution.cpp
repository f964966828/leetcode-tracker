int idx;

bool cmp(vector<int> a, vector<int> b){
    return a[idx] > b[idx];
}

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        idx = k;
        sort(score.begin(), score.end(), cmp);
        return score;
    }
};
