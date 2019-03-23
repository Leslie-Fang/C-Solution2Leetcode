#include <iostream>
#include <vector>
#include <deque>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
            	vector<vector<int> > res;
    	bool from_left2right = false;
    	deque<TreeNode*> ideq;
    	if(!root)
    	{
    		return res;
    	}
    	ideq.push_back(root);
    	while(ideq.size() != 0)
    	{
    		from_left2right = !from_left2right;
    		int len = ideq.size();
    		vector<int> sub_res;
    		deque<TreeNode*> sub_ideq;
    		for(int i=0;i<len;i++)
    		{
    			TreeNode* value;
    			if(from_left2right)
    			{
    				value = ideq.front();
    				ideq.pop_front();
    			}else
    			{   
    				value = ideq.back();
    				ideq.pop_back();
    			}
    			sub_res.push_back(value->val);
                
                
                
    			if(from_left2right)
    			{
	    			if(value->left)
	    			{
	    				sub_ideq.push_back(value->left);
	    			}
	    			if(value->right)
	    			{
						sub_ideq.push_back(value->right);
	    			}
    			}else
    			{
    				if(value->right)
	    			{
	    				sub_ideq.push_front(value->right);
	    			}
	    			if(value->left)
	    			{
						sub_ideq.push_front(value->left);
	    			}
    			}
                
                

    		}
    		res.push_back(sub_res);
    		for(deque<TreeNode*>::iterator it=sub_ideq.begin();it != sub_ideq.end();it++)
    		{
                ideq.push_back(*it);
    		}

    	}
        return res;
        
    }
};


int main()
{
	Solution *mySolution = new Solution();
}
