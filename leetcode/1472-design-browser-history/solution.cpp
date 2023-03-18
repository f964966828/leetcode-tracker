class BrowserHistory {
public:
    vector<string> history;
    int current;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        current++;
        history.erase(history.begin()+current, history.end());
        history.push_back(url);
    }
    
    string back(int steps) {
        current = max(0, current-steps);
        return history[current];
    }
    
    string forward(int steps) {
        current = min((int)history.size()-1, current+steps);
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
