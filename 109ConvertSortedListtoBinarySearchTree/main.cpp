#include <iostream>
#include <vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> temp;
        ListNode* cur = head;
        while(cur)
        {
        	temp.push_back(cur->val);
        	cur = cur->next;
        }
        TreeNode * res = NULL;
        int total_element = temp.size();
        if(total_element != 0)
        {
        	res = new TreeNode(temp[total_element/2]);
        	if(total_element == 1)
        	{
        		return res;
        	}else
        	{
        		res->left = sub(vector<int>(temp.begin(), temp.begin()+total_element/2));
        	}
        	if(total_element == 2)
        	{
        		return res;
        	}else
        	{
        		res->right = sub(vector<int>(temp.begin()+total_element/2+1,temp.end()));
        	}
        }
       
        return res;
    }
    TreeNode* sub(vector<int> temp)
    {   
    	TreeNode * res = NULL;
        int total_element = temp.size();
        if(total_element != 0)
        {
        	res = new TreeNode(temp[total_element/2]);
        	if(total_element == 1)
        	{
        		return res;
        	}else
        	{
        		res->left = sub(vector<int>(temp.begin(), temp.begin()+total_element/2));
        	}
        	if(total_element == 2)
        	{
        		return res;
        	}else
        	{
        		res->right = sub(vector<int>(temp.begin()+total_element/2+1,temp.end()));
        	}
        }
        return res;
    }
};
int main()
{
	return 1;
}