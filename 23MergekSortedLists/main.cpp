#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res= NULL;
        ListNode* start_node = NULL;
        int num = lists.size();
        cout<<"num is: "<<num<<endl;
        if(num == 0)
        {
        	return NULL;
        }else if(num == 1)
       	{
       		return lists[0];
       	}
        ListNode* temp[num];
        for(int i=0;i<num;i++)
        {
        	temp[i]=lists[i];
        }
        
        vector<int> small_list;
        while(1)
        {
        	small_list.clear();
        	int small = -99999;
        	int start = NULL;
        	for(int i=0;i<num;i++)
        	{
        		if(temp[i])
        		{
        			start = i+1;
        			small = temp[i]->val;
        			small_list.push_back(i);
                    break;
        		}
        	}
            if(small == -99999)
        	{
        		break;
        	}
	        for(int i=start;i<num;i++)
	        {
	        	if(temp[i] == NULL)
	        	{
	        		continue;
	        	}
                
	        	if(small < temp[i]->val)
	        	{
	        		continue;
	        	}else if(small == temp[i]->val)
	        	{
	        		small_list.push_back(i);
	        	}else
	        	{
                    
	        		small_list.clear();
	        		small_list.push_back(i);
	        		small = temp[i]->val;
	        	}
	        }
	        for(int i=0;i<small_list.size();i++)
	        {
	        	while(temp[small_list[i]]->val == small)
	        	{
	        		if(res)
	        		{
	        			res->next = new ListNode(temp[small_list[i]]->val);
                        res = res->next;
	        		}else
	        		{
	        			res = new ListNode(temp[small_list[i]]->val);
                        start_node = res;
	        		}
	        		temp[small_list[i]] = temp[small_list[i]]->next;
	        		if(temp[small_list[i]] == NULL)
	        		{
	        			break;
	        		}
	        	}
	        }
        }

        return start_node;
    }
};

int main(int argc, char ** argv)
{
	int i =0;
	if(i==NULL)
	{
		cout<<"Fuck"<<endl;
	}
	return 0;
}