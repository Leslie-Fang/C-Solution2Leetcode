#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};

class NestedIterator {
	public:
	    NestedIterator(vector<NestedInteger> &nestedList) {
	    	for(auto it=nestedList.rbegin();it!=nestedList.rend();it++){
	    		this->st.push(*it);
	    	}
	    }
	    
	    int next() {
	    	int res = this->st.top().getInteger();
	    	this->st.pop();
	    	return res;
	    }
	    
	    bool hasNext() {
	    	while(!st.empty()){
	    		NestedInteger cur = this->st.top();
	    		if(cur.isInteger()){
	    			return true;
	    		}else{
	    			this->st.pop();
	    			vector<NestedInteger> curList = cur.getList();
	    			for(auto it=curList.rbegin();it!=curList.rend();it++){
			    		this->st.push(*it);
			    	}
	    		}
	    	}
	    	return false;
	    }
	private:
		stack<NestedInteger> st;
};

int main(int argc, char ** argv){
	// Solution * NestedIterator = new NestedIterator();
	// string sinput;
	// getline(cin, sinput);
	// cout<<mySolution->bulbSwitch(stoi(sinput))<<endl;
	// delete mySolution;
	return 0;
}