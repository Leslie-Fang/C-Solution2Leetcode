#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

void printList(ListNode* root)
{
	ListNode* cur = root;
	cout<<"------start print list--------"<<endl;
	while(cur)
	{
		cout<<cur->val<<endl;
		cur = cur->next;
	}
	return;
}

class Solution {
public:
	ListNode* mergeSortedList(ListNode* left, ListNode* right)
	{
		ListNode* tempHead = NULL;
		ListNode* tempLeft = left;
		ListNode* tempRight = right;
		ListNode* tail = NULL;
		if(left == NULL)
		{
			return right;
		}else if(right == NULL)
		{
			return left;
		}
		while(tempLeft && tempRight)
		{
			if(tempLeft->val < tempRight->val)
			{
				if(!tempHead)
				{
					tempHead = tempLeft;
				}else
				{
					tail->next = tempLeft;
				}
				tail = tempLeft;
				tempLeft = tempLeft->next;
				tail->next = NULL;
			}else
			{
				if(!tempHead)
				{
					tempHead = tempRight;
				}else
				{
					tail->next = tempRight;
				}
				tail = tempRight;
				tempRight = tempRight->next;
				tail->next = NULL;
			}
		}
		if(tempLeft)
		{
			tail->next = tempLeft;
		}else if(tempRight)
		{
			tail->next = tempRight;
		}
		return tempHead;
	}

	// ListNode* cut(ListNode* node, int step)
	// {

	// }
    ListNode* sortList(ListNode* head) {
    	int index = 0;
    	ListNode* tempLeft = NULL;
		ListNode* tempRight = NULL;
		ListNode* temp = NULL;
		ListNode* last = NULL;
		ListNode* lasttemp = NULL;
		//ListNode* tail = NULL;
    	if(head)
    	{
    		temp = head;
    		int length = 0;
    		while (temp) {
	            ++length;
	            temp = temp->next;
        	}
        	for (int size = 1; size < length; size <<= 1) 
        	{
        		cout<<size<<"-------"<<endl;
        		temp = head;
        		index = 0;
        		last = NULL;
        		while(1)
        		{
        			if(index+size <= length)
        			{
        				if(last)
        				{
        					temp = last->next;
        					last->next = NULL;
        				}else
        				{
        					temp = head;
        				}
        				tempLeft = temp;
        				     				
        				//temp = cut(temp, size);
        				lasttemp = temp;
        				for(int i=0;i<size;i++)
        				{
        					lasttemp = temp;
        					temp = temp->next;
        				}
        				lasttemp->next = NULL;

        				index += size;
        				cout<<"index"<<index<<endl;
        				cout<<"length"<<length<<endl;
        				if(index+size <= length)
	        			{
	        				tempRight = temp;
	        				
	        				lasttemp = temp;
	        				for(int i=0;i<size;i++)
	        				{
	        					lasttemp = temp;
	        					temp = temp->next;
	        				}
	        				lasttemp->next = NULL;

	        				//temp = cut(temp, size);
	        				index += size;
	        				cout<<tempLeft->val<<endl;
	        				cout<<tempRight->val<<endl;
	        				tempLeft = mergeSortedList(tempLeft, tempRight);

	        				cout<<"pinrt tempLeft"<<endl;
	        				printList(tempLeft);

	        				if(last)
	        				{
	        					last->next = tempLeft;		
	        				}

	        				ListNode* p = tempLeft;
	        				while(p->next)
	        				{
	        					p = p->next;
	        				}
	        				last = p;
	        				//last = lasttemp;
	        				
	        				last->next = temp;

	        				printList(head);

	        			}else
	        			{
	        				tempLeft = mergeSortedList(tempLeft, temp);
	        				last->next = tempLeft;
	        				break;
	        			}
        			}else
        			{

        				break;
        			}
        		}
        		printList(head);
        	}
    	}
    	return head;
    }
};

ListNode* getList(string input)
{
	vector<string> inputV;
	SplitString(input, inputV, "->");
	ListNode* root = NULL;
	ListNode* cur = NULL;
	ListNode* temp = NULL;
	if(inputV.size() >= 1)
	{
		root = new ListNode(stoi(inputV[0]));
		cur = root;
		for(int i=1;i<inputV.size();i++)
		{
			temp = new ListNode(stoi(inputV[i]));
			cur->next = temp;
			cur = temp;
		}
	}
	return root;
}


void deleteList(ListNode* root)
{
	ListNode* cur = root;
	ListNode* last = root;
	while(cur)
	{
		cur = cur->next;
		delete last;
		last = cur;
	}
	return;
}

void mainf()
{
	string input;
	getline(cin,input);
	ListNode* root = getList(input);
	printList(root);

	Solution * mySolution = new Solution();

	root = mySolution->sortList(root);
	printList(root);
	delete mySolution;
	deleteList(root);
	return;
}

void testMerge()
{	
	string input;
	getline(cin,input);
	string input2;
	getline(cin,input2);

	ListNode* root = getList(input);
	ListNode* root2 = getList(input2);

	Solution * mySolution = new Solution();

	root = mySolution->mergeSortedList(root, root2);
	printList(root);
	delete mySolution;
	deleteList(root);
	return;
}

int main(int argc, char ** argv)
{
	mainf();
	//testMerge();

	return 0;
}