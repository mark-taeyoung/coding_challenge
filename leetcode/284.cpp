/**
 * 284. Peeking Iterator
 * */


/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
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
    
    bool isFront;
    int nextValue;
    bool isLast;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        
        isFront = true;
        isLast = false;
        nextValue = nums[0];
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int temp = nextValue;
        if (isLast) {
            isLast = false;
            return temp;
        }
        
        if (isFront) {
            nextValue = Iterator::next();
            isFront = false;
        }
    
        if (Iterator::hasNext()) {
            nextValue = Iterator::next();
        }
        
        if (!Iterator::hasNext()) {
            isLast = true;
        }

	    return temp;
    }
	
	bool hasNext() const {
        if (isLast) {
            return true;
        }
        
        return Iterator::hasNext();
	}
};
 