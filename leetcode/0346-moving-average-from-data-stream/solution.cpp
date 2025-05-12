class MovingAverage {
public:
    int sum;
    int size;
    queue<int> q;

    MovingAverage(int size) {
        sum = 0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (double) sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
