/**
Runtime: 459 ms, Beats: 84.66%
Memory: 165 MB, Beats: 84.52%
**/
class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> mMap; // key - <value, list iter>
    list<int> mList; // priority from high to low
    int mCap;
public:
    LRUCache(int capacity) : mCap(capacity) 
    {
    }

    void moveKeyToListFront(int key){
        mList.splice(mList.begin(), mList, mMap[key].second);
        mMap[key].second = mList.begin();
    }
    
    int get(int key) {
        if(mMap.count(key) == 0){
            return -1;
        }else{
            moveKeyToListFront(key);
            return mMap[key].first;
        }
    }
    
    void put(int key, int value) {
        if(mMap.count(key) != 0){
            moveKeyToListFront(key);
            mMap[key].first = value;
            return;
        }
        if(mList.size()+1 > mCap){
            mMap.erase(mList.back());
            mList.pop_back();
        }
        mList.push_front(key);
        mMap[key] = make_pair(value, mList.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
