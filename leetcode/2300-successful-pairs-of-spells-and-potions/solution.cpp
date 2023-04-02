class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<long long> seq;
        for(int num: potions) seq.push_back(num);

        sort(seq.begin(), seq.end());

        vector<int> ans;
        for(int s: spells){
            auto iter = lower_bound(seq.begin(), seq.end(), ceil(success / (double) s));
            ans.push_back(seq.end() - iter);
        }

        return ans;
    }
};
