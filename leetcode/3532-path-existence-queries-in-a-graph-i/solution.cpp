class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        vector<int> vec;
        for (int num : st) vec.push_back(num);
            
        n = vec.size();
        int groupI = 0, vecI = 0;
        map<int, int> group;
        while (vecI < n) {
            group[vec[vecI]] = groupI;
            while (vecI + 1 < n && vec[vecI + 1] <= vec[vecI] + maxDiff) {
                group[vec[++vecI]] = groupI;
            }
            vecI++;
            groupI++;
        }

        vector<bool> ans;
        for (auto &query : queries) {
            ans.push_back(group[nums[query[0]]] == group[nums[query[1]]]);
        }
        return ans;
    }
};
