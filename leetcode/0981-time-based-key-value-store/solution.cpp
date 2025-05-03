class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &vec = mp[key];
        auto iter = lower_bound(vec.begin(), vec.end(), make_pair(timestamp, ""));
        while (iter != vec.begin() && (iter == vec.end() || iter->first > timestamp)) iter--;
        if (iter != vec.end() && iter->first <= timestamp) {
            return iter->second;
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
