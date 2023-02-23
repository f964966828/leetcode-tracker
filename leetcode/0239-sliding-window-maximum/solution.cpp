typedef pair<int, int> pii;

bool cmp(pii a, pii b){
    return a.first > b.first;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<pii> info(nums.size());
        for(int i=0; i<nums.size(); i++){
            info[i].first = nums[i];
            info[i].second = i;
        }
        sort(info.begin(), info.end(), cmp);

        set<int> s;
        for(int i=0; i<nums.size()-k+1; i++) s.insert(i);

        vector<int> ans(nums.size()-k+1);
        for(pii t: info){
            auto lit = s.lower_bound(t.second-k+1);
            auto rit = s.upper_bound(t.second);
            if(lit == rit) continue;
            for(auto it=lit; it!=rit; it++){
                ans[*it] = t.first;
            }
            s.erase(lit, rit);
        }

        return ans;
    }
};
