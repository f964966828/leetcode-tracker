class Solution {
public:
    queue<int> q;
    vector<int> p;
    vector<map<int, int>> factors;
    vector<pair<int, int>> bounds;
    vector<bool> visited;

    bool isPrime(int num) {
        if (num == 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        int gx = find(x);
        int gy = find(y);
        
        bool flag = false;
        for (auto & [prime, time] : factors[gy]) {
            if (factors[gx].find(prime) != factors[gx].end()) flag = true;
        }
        if (flag) {
            p[gy] = gx;
            for (auto & [prime, time] : factors[gy]) {
                factors[gx][prime] = max(factors[gx][prime], time);
            }
            bounds[gx].first = min(bounds[gx].first, bounds[gy].first);
            bounds[gx].second = max(bounds[gx].second, bounds[gy].second);

            q.push(gx);
            visited[gx] = false;
        }
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> primes;
        for (int i = 1; i <= 1e5; i++) {
            if (isPrime(i)) primes.push_back(i);
        }

        int n = nums.size();
        p.resize(n);
        bounds.resize(n);
        factors.resize(n);
        visited.resize(n, false);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (auto & prime : primes) {
                while (num % prime == 0) {
                    num /= prime;
                    factors[i][prime]++;
                }
                if (num == 1) break;
            }

            q.push(i);
            p[i] = (i);
            bounds[i] = {i, i};
        }

        while (!q.empty()) {
            int idx = find(q.front());
            q.pop();
            
            if (visited[idx]) continue; 
            visited[idx] = true;

            int left = bounds[idx].first - 1;
            int right = bounds[idx].second + 1;
            if (left >= 0) merge(idx, left);
            if (right < n) merge(idx, right);
        }

        int cur = 0;
        vector<int> ans;
        while (cur != n) {
            int g = find(cur), num = 1;
            for (auto & [prime, time] : factors[g]) {
                while (time--) num *= prime;
            }
            ans.push_back(num);
            cur = bounds[g].second + 1;
        }
        return ans;
    }
};
