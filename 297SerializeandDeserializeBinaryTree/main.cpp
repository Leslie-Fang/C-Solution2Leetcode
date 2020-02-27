#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string res = "";
    	queue<TreeNode*> list;
    	queue<int> index;
    	bool exsit_child = true;
    	TreeNode * cur = NULL;
    	int curindex;
    	int lastindex;
    	int loopnum = 1;

    	if(root)
    	{
    		list.push(root);
    		index.push(0);
    		loopnum = 1;    		
    		while(1)
    		{
    			if(!exsit_child)
    			{
    				break;
    			}
    			int loop = list.size();
    			exsit_child = false;
    			lastindex = -1;
    			curindex = 0;
    			for(int i=0;i<loop;i++)
    			{
    				cur = list.front();
    				curindex = index.front();

    				for(int i=0;i<(curindex-lastindex-1);i++)
    				{
    					res += "*,";
    				}
  
	    			res += to_string(cur->val);
	    			res += ",";
	    			if(cur->left || cur->right)
	    			{
	    				exsit_child = true;
	    			}
	    			if(cur->left)
	    			{
	    				list.push(cur->left);
	    				index.push(curindex*2);
	    			}
	    			if(cur->right)
	    			{
	    				list.push(cur->right);
	    				index.push(curindex*2+1);
	    			}
    				lastindex = curindex;
    				list.pop();
    				index.pop();
    			}
    			for(int i=0;i<(loopnum-curindex-1);i++)
    			{
    					res += "*,";
    			}
    			loopnum = loopnum * 2;
	    	}
    	}
    	//cout<<res<<endl;
    	return res;
    }

	void DFS(TreeNode * root)
	{
		if(root)
		{
			cout<<root->val;
			cout<<","<<endl;
			DFS(root->left);
			DFS(root->right);
		}else
		{
			cout<<"*";
			cout<<","<<endl;
		}
		return;
	}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	TreeNode* root = NULL;
    	std::string::size_type pos1, pos2;
    	pos1 = 0;
    	string temp = "";
        int length = data.length();
        queue<TreeNode*> nodelist;
        if(length != 0)
        {
        	pos2 = data.find(",");
        	temp = data.substr(pos1, pos2-pos1);
        	root = new TreeNode(stoi(temp));
        	pos1 = pos2 + 1;

        	TreeNode* cur = root;
        	nodelist.push(root);

        	while(pos1 < length-1)
        	{
        		//cout<<pos1<<"  xxxx"<<endl;
        		int loop = nodelist.size();
        		for(int i=0;i<loop;i++)
        		{
        			cur = nodelist.front();
        			if(cur)
        			{
        				pos2 = data.find(",", pos1);
        				if(std::string::npos == pos2)
        				{
        					break;
        				}
			        	temp = data.substr(pos1, pos2-pos1);
			        	pos1 = pos2 + 1;

	        			if(temp != "*")
	        			{
	        				cur->left = new TreeNode(stoi(temp));
	        			}
	        			nodelist.push(cur->left);
	        			pos2 = data.find(",", pos1);
	        			if(std::string::npos == pos2)
        				{
        					break;
        				}
			        	temp = data.substr(pos1, pos2-pos1);
			        	pos1 = pos2 + 1;
	        			if(temp != "*")
	        			{
	        				cur->right = new TreeNode(stoi(temp));
	        			}
	        			nodelist.push(cur->right);
        			}else
        			{
        				pos1 = pos1 + 4;

        				nodelist.push(NULL);
        				nodelist.push(NULL);
        			}
        			nodelist.pop();
        		}

        	}

        }

        //DFS(root);
        return root;
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin,input);
	Codec * myCodec;
	string res = myCodec->serialize(myCodec->deserialize(input));
	cout<<res<<endl;
	//myCodec->deserialize(input);
	//delete myCodec;
	//cout<<"xxxx"+std::string(5, "*,")<<endl;
	return 0;
}