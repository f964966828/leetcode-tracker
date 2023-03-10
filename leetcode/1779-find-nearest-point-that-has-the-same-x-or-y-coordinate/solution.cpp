class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mn = 1e9, idx = -1;
        for(int i=0; i<points.size(); i++){
            int nx = points[i][0], ny = points[i][1];
            if(x != nx && y != ny) continue;
            int dis = abs(x-nx) + abs(y-ny);
            if(dis < mn){
                mn = dis;
                idx = i;
            }
        }

        return idx;
    }
};
