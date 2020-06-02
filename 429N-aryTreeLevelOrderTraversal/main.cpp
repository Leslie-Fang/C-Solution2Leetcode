#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
        	return res;
        }
        queue<Node *> myQueue;
        vector<int> temp;
        myQueue.push(root);
        while(!myQueue.empty()){
        	int size = myQueue.size();
        	temp.clear();
        	for(int i=0;i<size;i++){
        		temp.push_back(myQueue.front()->val);
        		for(auto node:myQueue.front()->children){
        			if(node){
        				myQueue.push(node);
        			}
        		}
        		myQueue.pop();
        	}
        	res.push_back(temp);
        }

        return res;
    }
};

int main(int argc, char ** argv){
	return 0;
}