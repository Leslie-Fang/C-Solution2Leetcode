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
    	bool exsit_child = true;
    	TreeNode * cur = NULL;
    	if(root)
    	{
    		list.push(root);    		
    		while(1)
    		{
    			if(!exsit_child)
    			{
    				break;
    			}
    			int loop = list.size();
    			exsit_child = false;
	    		for(int i=0;i<loop;i++)
	    		{
	    			cur = list.front();
	    			if(cur != NULL)
	    			{
	    				res += to_string(cur->val);
	    				res += ",";
	    				if(cur->left || cur->right)
	    				{
	    					exsit_child = true;
	    				}
	    				list.push(cur->left);
	    				list.push(cur->right);
	    			}else
	    			{
	    				res += '*';
	    				res += ',';
	    				list.push(NULL);
	    				list.push(NULL);
	    			}
	    			list.pop();
	    		}
	    	}
    	}
    	cout<<res<<endl;
    	return res;
    }

	void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
	{
	  std::string::size_type pos1, pos2;
	  pos2 = s.find(c);
	  pos1 = 0;
	  while(std::string::npos != pos2)
	  {
	    v.push_back(s.substr(pos1, pos2-pos1));
	 
	    pos1 = pos2 + c.size();
	    pos2 = s.find(c, pos1);
	  }
	  if(pos1 != s.length())
	    v.push_back(s.substr(pos1));
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
    	//new TreeNode(1);
        std::vector<std::string> input;
        SplitString(data, input, ",");

        int length = input.size();
        int index = 0;
        //vector<TreeNode*> nodelist;
        queue<TreeNode*> nodelist;
        if(length != 0)
        {
        	root = new TreeNode(stoi(input[0]));
        	TreeNode* cur = root;
        	nodelist.push(root);
        	index += 1;

        	while(index < length)
        	{
        		int loop = nodelist.size();
        		for(int i=0;i<loop;i++)
        		{
        			cur = nodelist.front();
        			if(cur)
        			{
	        			if(input[index] != "*")
	        			{
	        				cur->left = new TreeNode(stoi(input[index]));
	        			}
	        			nodelist.push(cur->left);
	        			index += 1;
	        			if(input[index] != "*")
	        			{
	        				cur->right = new TreeNode(stoi(input[index]));
	        			}
	        			nodelist.push(cur->right);
	        			index += 1;
        			}else
        			{
        				index += 2;
        				nodelist.push(NULL);
        				nodelist.push(NULL);
        			}
        			nodelist.pop();
        		}

        	}

        }
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
	return 0;
}