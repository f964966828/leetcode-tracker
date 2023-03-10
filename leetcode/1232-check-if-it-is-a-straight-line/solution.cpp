class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> xdiff, ydiff;
        for(int i=1; i<coordinates.size(); i++){
            vector<int> p1 = coordinates[i-1];
            vector<int> p2 = coordinates[i];
            int x1 = p1[0], x2 = p2[0];
            int y1 = p1[1], y2 = p2[1];
            xdiff.push_back(x2 - x1);
            ydiff.push_back(y2 - y1);
        }

        for(int i=1; i<xdiff.size(); i++){
            int dx1 = xdiff[i-1], dx2 = xdiff[i];
            int dy1 = ydiff[i-1], dy2 = ydiff[i];
            if(dx2*dy1 != dx1*dy2)
                return false;
        }

        return true;
    }
};
