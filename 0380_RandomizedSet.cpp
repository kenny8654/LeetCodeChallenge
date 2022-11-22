/**
Runtime: 261 ms, Beats: 83.73%
Memory: 96.8 MB, Beats: 93.6%
**/
class RandomizedSet {
private:
    unordered_set<int> mSet;
public:
    RandomizedSet() 
    {
    }
    
    bool insert(int val) {
        auto it = mSet.find(val);
        if(it != mSet.end())
            return false;
        
        mSet.insert(val);
        return true;    
    }
    
    bool remove(int val) {
        auto it = mSet.find(val);
        if(it == mSet.end())
            return false;
        
        mSet.erase(it);
        return true;
    }
    
    int getRandom() {
        int iRand = rand() % int(mSet.size());
        auto it = mSet.begin();
        advance(it, iRand);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
