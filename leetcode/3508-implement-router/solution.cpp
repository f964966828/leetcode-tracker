class Router {
public:
    int limit;
    queue<tuple<int, int, int>> q;
    set<tuple<int, int, int>> st;
    unordered_map<int, pair<int, vector<int>>> ump;

    Router(int limit) {
        this->limit = limit;
    }
    
    bool addPacket(int src, int des, int time) {
        tuple<int, int, int> key = {src, des, time};
        if (st.find(key) == st.end()) {
            q.push(key);
            st.insert(key);
            ump[des].second.push_back(time);

            if (q.size() > limit) forwardPacket();
            return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto [src, des, time] = q.front();
        q.pop();
        st.erase({src, des, time});
        ump[des].first++;
        return {src, des, time};
    }
    
    int getCount(int des, int startTime, int endTime) {
        auto &[head, vec] = ump[des];
        auto lower = lower_bound(vec.begin() + head, vec.end(), startTime);
        auto upper = upper_bound(vec.begin() + head, vec.end(), endTime);
        return upper - lower;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
