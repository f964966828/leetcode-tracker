class TaskManager {
public:
    unordered_map<int, pair<int, int>> ump;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto & task : tasks) {
            int userId = task[0], taskId = task[1], prior = task[2];
            ump[taskId] = {prior, userId};
            pq.push({prior, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ump[taskId] = {priority, userId};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = ump[taskId].second;
        ump[taskId] = {newPriority, userId};
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        ump.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();

            if (ump.find(taskId) != ump.end() && ump[taskId].first == priority) {
                int userId = ump[taskId].second;
                ump.erase(taskId);
                return userId;
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
