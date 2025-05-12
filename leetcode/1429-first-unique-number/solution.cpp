class FirstUnique {
public:

    queue<int> q;
    unordered_map<int, int> mp;

    FirstUnique(vector<int>& nums) {
        for (int &num : nums) add(num);
    }
    
    int showFirstUnique() {
        if (q.empty()) {
            return -1;
        } else {
            return q.front();
        }
    }
    
    void add(int value) {
        if (mp[value]++ == 0) q.push(value);
        while (!q.empty() && mp[q.front()] >= 2) q.pop();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
