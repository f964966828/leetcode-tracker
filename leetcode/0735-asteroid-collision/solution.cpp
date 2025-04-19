class Solution {
public:
    void push(vector<int>& vec, int num) {
        if (vec.empty()) {
            vec.push_back(num);
        } else {
            int tp = vec[vec.size() - 1];
            if (tp > 0 && num < 0) {
                vec.pop_back();
                if (abs(num) > abs(tp)) {
                    push(vec, num);
                } else if (abs(num) < abs(tp)) {
                    push(vec, tp);
                }
            } else {
                vec.push_back(num);
            }
        }
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int num : asteroids) {
            push(ans, num);
        }

        return ans;
    }
};
