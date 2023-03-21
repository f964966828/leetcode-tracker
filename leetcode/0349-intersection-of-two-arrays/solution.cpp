class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        for(int num: nums1) mp1[num]++;
        for(int num: nums2) mp2[num]++;

        vector<int> ans;
        for(auto e: mp1){
            if(mp2[e.first])
                ans.push_back(e.first);
        }

        return ans;
    }
};
