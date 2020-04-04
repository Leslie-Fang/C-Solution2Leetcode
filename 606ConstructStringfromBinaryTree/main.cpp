#include <iostream>
#include <string>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	void DFS(TreeNode* c, string & res)
	{
		if(!c)
		{
			return;
		}
		res += to_string(c->val);
		if(c->left)
		{
			res += "(";
            DFS(c->left, res);
			res += ")";
		}
		if(c->right)
		{
			if(!c->left)
			{
				res += "()";
			}
			res += "(";
            DFS(c->right, res);
			res += ")";
		}
		return;
	}
    string tree2str(TreeNode* t) {
    	string res;
    	DFS(t, res);
    	return res;
    }
};

int main(int argc, char ** argv)
{

}