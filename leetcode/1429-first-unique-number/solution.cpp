class FirstUnique {
public:

    vector<int> nums;
    map<int, int> mp;

    FirstUnique(vector<int>& nums) {
        for (int num : nums) mp[num]++;
        for (int num : nums) {
            if (mp[num] == 1) this->nums.push_back(num);
        }
    }
    
    int showFirstUnique() {
        for (int num : nums) {
            if (mp[num] == 1) return num;
        }
        return -1;
    }
    
    void add(int value) {
        mp[value]++;
        if (mp[value] == 1) {
            nums.push_back(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
