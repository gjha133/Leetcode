class SmallestInfiniteSet {
public:
    int mn;
    set<int> set;
    SmallestInfiniteSet() {
        mn = 1;
    }
    
    int popSmallest() {
        if(set.size()) {
            int front = *set.begin();
            set.erase(set.begin());
            return front;
        } else {
            mn++;
            return mn-1;
        }
    }
    
    void addBack(int num) {
        if(mn > num) set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */