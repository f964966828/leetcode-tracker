class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq; // (increased_ratio, index)
        for (int i = 0; i < classes.size(); i++) {
            double pass = classes[i][0];
            double total = classes[i][1];
            double diff = (pass + 1) / (total + 1) - pass / total;
            pq.push({diff, i});
        }

        while (extraStudents--) {
            int idx = pq.top().second;
            pq.pop();

            double pass = ++classes[idx][0];
            double total = ++classes[idx][1];
            double diff = (pass + 1) / (total + 1) - pass / total;
            pq.push({diff, idx});
        }

        double sum = 0.0;
        for (auto &item : classes) {
            sum += (double) item[0] / item[1];
        }
        return sum / classes.size();
    }
};
