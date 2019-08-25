#include <iostream>
#include <vector>
#include <queue>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    	vector<TreeNode*> res;
    	vector<TreeNode*> delete_n;
    	if(!root)
    	{
    		return res;
    	}
    	queue<TreeNode*> looking;
    	looking.push(root);
    	res.push_back(root);
    	while(1)
    	{
    		int count = looking.size();
    		if(count <= 0)
    		{
    			break;
    		}
    		for(int i=0;i<count;i++)
    		{
    			for(vector<int>::iterator it = to_delete.begin();it != to_delete.end();it++)
    			{
    				if(*it == looking.front()->val)
    				{
    					delete_n.push_back(looking.front());
    					bool finding = false;
    					if(looking.front()->left)
    					{
    						for(vector<int>::iterator it2 = to_delete.begin();it2 != to_delete.end();it2++)
					    	{
					    		if( looking.front()->left->val == (*it2))
					    		{
					    			finding = true;
					    		}
					    	}
					    	if(!finding)
					    	{
					    		res.push_back(looking.front()->left);
					    	}
    						
    					}
    					finding = false;
    					if(looking.front()->right)
    					{
    						for(vector<int>::iterator it2 = to_delete.begin();it2 != to_delete.end();it2++)
					    	{
					    		if( looking.front()->right->val == (*it2))
					    		{
					    			finding = true;
					    		}
					    	}
    						if(!finding)
					    	{
					    		res.push_back(looking.front()->right);
					    	}
    					}
    				}
    			}
    			if(looking.front()->left)
	    		{
	    			looking.push(looking.front()->left);
	    		}
	    		if(looking.front()->right)
	    		{
	    			looking.push(looking.front()->right);
	    		}
    			looking.pop();
    		}
    	}
   //  	for(vector<TreeNode*>::iterator it = res.begin(); it != res.end(); it++)
 		// {
 		// 	cout<<int((*it)->val)<<endl;
	  //   	// for(vector<int>::iterator it2 = to_delete.begin();it2 != to_delete.end();it2++)
	  //   	// {
	  //   	// 	if( int((*it)->val) == (*it2))
	  //   	// 	{
	  //   	// 		res.erase(it);
	  //   	// 	}
	  //   	// }
 		// }

    	looking.push(root);
    	while(1)
    	{
    		int count = looking.size();
    		if(count <= 0)
    		{
    			break;
    		}
    		for(int i=0;i<count;i++)
    		{
    			if(looking.front()->left)
		    	{
		    		looking.push(looking.front()->left);
		    	}
		    	if(looking.front()->right)
		    	{
		    		looking.push(looking.front()->right);
		    	}
    			for(vector<TreeNode*>::iterator it = delete_n.begin();it != delete_n.end();it++)
    			{
	    			if(looking.front()->left == *it)
			    	{
			    		looking.front()->left = NULL;
			    	}
			    	if(looking.front()->right == *it)
			    	{
			    		looking.front()->right = NULL;
			    	}
    			}
    			looking.pop();
    		}

    	}
    	return res;    
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	delete mySolution;
	return 0;
}