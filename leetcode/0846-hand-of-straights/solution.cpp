class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (int num : hand) mp[num]++;

        while (!mp.empty()) {
            int num = mp.begin()->first;
            for (int i = num; i < num + groupSize; i++) {
                if (mp.find(i) == mp.end()) return false;
                if (--mp[i] == 0) mp.erase(i);
            }
        }

        return true;
    }
};
