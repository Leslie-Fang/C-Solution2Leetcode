#include <iostream>
#include <queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int countNodes(TreeNode* root) {
    	queue<TreeNode *> myQueue;
    	int res = 0;
    	if(root){
    		myQueue.push(root);
    		int size = 0;
    		TreeNode * tmp;
    		while(1){
    			size = myQueue.size();
    			if(size == 0){
    				break;
    			}
    			//cout<<size<<endl;
    			res += size;
    			while(size){
    				tmp = myQueue.front();
    				if(tmp->left){
    					myQueue.push(tmp->left);
    				}
    				if(tmp->right){
						myQueue.push(tmp->right);
    				}
    				myQueue.pop();
    				size --;
    			}

    		}
    	}
    	return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}

