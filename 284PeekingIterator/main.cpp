#include <iostream>
#include <vector>
using namespace std;


class PeekingIterator : public Iterator {
public:
	int cur;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if(Iterator::hasNext()){
	    	cur = Iterator::next();
	    }
		else{
			cur = -1;
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return cur;
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = cur;
	    cur = Iterator::hasNext()?Iterator::next():-1;
	    return res;
	}
	
	bool hasNext() const {
		return Iterator::hasNext();
	    
	}
};

int main(int argc, char ** argv){
	int a[3] = {1,2,3};
	vector<int> nums(a, a+3);
	PeekingIterator tt = PeekingIterator(nums);
	cout<<tt.hasNext()<<endl;
	return 0;
}