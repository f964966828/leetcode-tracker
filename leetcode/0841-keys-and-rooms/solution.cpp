class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        stack<int> stk;
        stk.push(0);
        while (!stk.empty()) {
            int from = stk.top();
            stk.pop();

            visited[from] = true;
            for (int to : rooms[from]) {
                if (!visited[to]) stk.push(to);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
