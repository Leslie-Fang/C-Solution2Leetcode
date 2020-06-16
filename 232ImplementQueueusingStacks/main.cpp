#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    int size;
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        this->size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
    	while(!s1.empty()){
    		s2.push(s1.top());
    		s1.pop();
    	}
    	s2.push(x);
    	while(!s2.empty()){
    		s1.push(s2.top());
    		s2.pop();
    	}
    	return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = s1.top();
        s1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};


int main(int argc, char ** argv){
	MyQueue * queue = new MyQueue();

	queue.push(1);
	queue.push(2);  
	queue.peek();  // returns 1
	queue.pop();   // returns 1
	queue.empty(); // returns false
	delete queue;
	return 0;
}