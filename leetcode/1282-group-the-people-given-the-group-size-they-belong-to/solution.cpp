class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> empty_vec;
        map<int, vector<int>> mp;
        for(int i=0; i<groupSizes.size(); i++){
            int g = groupSizes[i];
            if(mp.find(g) == mp.end()) mp[g] = empty_vec;
            mp[g].push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> temp;
        for(auto item: mp){
            int n = item.first;
            vector<int> vec = item.second;
            for(auto num: vec){
                temp.push_back(num);
                if(temp.size() == n){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return ans;
    }
};
