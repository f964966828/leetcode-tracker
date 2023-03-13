class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string word: words)
            mp[word]++;
        
        vector<pair<int, string>> v;
        for(auto e: mp) 
            v.push_back({-e.second, e.first});

        sort(v.begin(), v.end());

        vector<string> ans;
        for(auto e: v){
            ans.push_back(e.second);
            if(--k == 0) break;
        }

        return ans;
    }
};
