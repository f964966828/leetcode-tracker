class RandomizedSet {
public:
    vector<int> vec; //index2val
    unordered_map<int, int> mp; // val2index

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        mp[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        vec[mp[val]] = vec.back();
        vec.pop_back();
        mp[vec[mp[val]]] = mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
