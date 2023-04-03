class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> ms;
        for(int p: people) ms.insert(p);

        int ans = 0;
        while(!ms.empty()){
            auto iter1 = --ms.end();
            int target = limit - *iter1;
            ms.erase(iter1);

            auto iter2 = ms.upper_bound(target);
            if(iter2 != ms.begin()) ms.erase(--iter2);

            ans++;
        }

        return ans;
    }
};
