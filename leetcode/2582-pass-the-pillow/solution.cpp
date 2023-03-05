class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 1, pos = 1;
        while(time){
            int move = min(time, n-1);
            pos += dir * move;
            time -= move;
            dir *= -1;
        }
        return pos;
    }
};
