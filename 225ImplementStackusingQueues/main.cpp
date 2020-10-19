#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> myQueue;;
    MyStack() {
    	//queue<int> myQueue;
        //myQueue.
    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	myQueue.push(x);
    	int tmp;
    	for(int i=0;i<myQueue.size()-1;i++){
    		tmp = myQueue.front();
    		myQueue.pop();
    		myQueue.push(tmp);
    	}
    	return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int tmp = myQueue.front();
    	myQueue.pop();
    	return tmp;
        //return myQueue.pop();
    }
    
    /** Get the top element. */
    int top() {
    	int tmp = myQueue.front();

    	return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
    }
};

int main(int argc, char ** argv){
	MyStack * myMyStack = new MyStack();

	return 0;
}