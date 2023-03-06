/**
Runtime: 83 ms, Beats: 95.3%
Memory: 38.9 MB, Beats: 47.52%
**/
class MyCalendar {
private:
    map<int, int> mMap;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mMap.upper_bound(start);
        if (it == mMap.end() || it->second >= end){
            mMap[end] = start;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
