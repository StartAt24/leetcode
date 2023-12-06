#include  <vector>

using namespace std;
//Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
    Data* data;
 public:
	Iterator(const vector<int>& nums);
		Iterator(const Iterator& iter);

		// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        _data = nums;
        _size = _data.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        int peekPointer = _nextPointer; 
        return _data[peekPointer];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = _data[_nextPointer];
        _nextPointer++;
        return ret;
	}
	
	bool hasNext() const {
        return _nextPointer <= _size-1;
	}

private:
    vector<int> _data;
    int _nextPointer = 0;
    int _size;
};