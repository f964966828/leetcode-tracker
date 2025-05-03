class SnakeGame {
public:
    int width;
    int height;

    int row;
    int col;
    int time;
    int length;

    vector<vector<int>> food;
    vector<vector<int>> grid;

    map<char, pair<int, int>> mp = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;

        this->row = 0;
        this->col = 0;
        this->time = 0;
        this->length = 0;
        
        grid.resize(height);
        for (int i = 0; i < height; i++) {
            grid[i].resize(width, -1);
        }
        grid[row][col] = time++;
    }
    
    int move(string direction) {
        int newRow = row + mp[direction[0]].first;
        int newCol = col + mp[direction[0]].second;
        if (newRow < 0 || newRow >= height || newCol < 0 || newCol >= width) {
            return -1;
        } else if (grid[newRow][newCol] != -1 && time - grid[newRow][newCol] <= length) {
            return -1;
        } else {
            row = newRow;
            col = newCol;
            grid[row][col] = time++;
            if (length < food.size() && food[length][0] == row && food[length][1] == col) {
                length++;
            }
            return length;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
