// /*
//  * Below is the interface for Iterator, which is already defined for you.
//  * **DO NOT** modify the interface for Iterator.
//  *
//  *  class Iterator {
//  *		struct Data;
//  * 		Data* data;
//  *  public:
//  *		Iterator(const vector<int>& nums);
//  * 		Iterator(const Iterator& iter);
//  *
//  * 		// Returns the next element in the iteration.
//  *		int next();
//  *
//  *		// Returns true if the iteration has more elements.
//  *		bool hasNext() const;
//  *	};
//  */

// class PeekingIterator : public Iterator {
// public:
// 	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
// 	    // Initialize any member here.
// 	    // **DO NOT** save a copy of nums and manipulate it directly.
// 	    // You should only use the Iterator interface methods.
	    
// 	}
	
//     // Returns the next element in the iteration without advancing the iterator.
// 	int peek() {
        
// 	}
	
// 	// hasNext() and next() should behave the same as in the Iterator interface.
// 	// Override them if needed.
// 	int next() {
	    
// 	}
	
// 	bool hasNext() const {
	    
// 	}
// };
#include <vector>
using namespace std ;
// Below is the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasNextElement;

public:
    PeekingIterator(const vector<int>& nums)
        : Iterator(nums) {

        hasNextElement = Iterator::hasNext();

        if (hasNextElement) {
            nextElement = Iterator::next();
        }
    }

    // Returns the next element without advancing
    int peek() {
        return nextElement;
    }

    // Returns the next element and advances
    int next() {
        int result = nextElement;

        hasNextElement = Iterator::hasNext();

        if (hasNextElement) {
            nextElement = Iterator::next();
        }

        return result;
    }

    // Checks whether another element exists
    bool hasNext() const {
        return hasNextElement;
    }
};