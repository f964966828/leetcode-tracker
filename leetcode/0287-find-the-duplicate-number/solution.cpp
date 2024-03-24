class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for (int num: nums) {
            if (s.find(num) != s.end()) {
                return num;
            } else {
                s.insert(num);
            }
        }
        
        return -1;
    }
};
