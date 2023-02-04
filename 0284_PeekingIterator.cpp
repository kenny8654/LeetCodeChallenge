/**
Runtime: 3 ms, Beats: 76.31%
Memory: 7.5 MB, Beats: 69.90%
**/
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    bool mHasNext;
    int mNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    getNext();
	}
	
    void getNext() {
        mHasNext = Iterator::hasNext();
        if(mHasNext)
            mNext = Iterator::next();
    }

	int peek() {
        return mNext;
	}

    int next() {
        int ret = mNext;
        getNext();
	    return ret;
	}
	
	bool hasNext() const {
	    return mHasNext;
	}
};
