class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) st.insert(i);
    }
    
    int popSmallest() {
        int num = *st.begin();
        st.erase(st.begin());
        return num;
    }
    
    void addBack(int num) {
        st.insert(num);
    }

private:
    set<int> st;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
