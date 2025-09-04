class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(z - x), dy = abs(z - y);
        return (dx == dy ? 0 : (dx < dy ? 1 : 2));
    }
};
