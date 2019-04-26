#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
    	cout<<"In reorder List now"<<endl;
    	if(head == NULL)
    	{
    		return;
    	}
    	int count = 1;
    	vector<ListNode *> stack;
    	ListNode* previous_node = head;
    	ListNode* current_node = head->next;
    	stack.push_back(head);
    	while(current_node != NULL)
    	{
    		stack.push_back(current_node);
    		count += 1;
    		previous_node = current_node;
    		current_node = current_node -> next;
    	}
    	if(count <= 2)
    	{
    		return;
    	}
    	ListNode* temp;
    	vector<ListNode *>:: iterator it1 = stack.begin();
    	vector<ListNode *>:: iterator it2 = stack.end()-1;
    	while((it2 - it1) > 1)
    	{
    		temp = (*(it1))->next;
    		(*(it1)) -> next = *(it2);
    		(*(it2)) -> next = temp;
    		it1 += 1;
    		it2 -= 1;
    	}

    	current_node = head;
    	for(int i=0;i<count-1;i++)
    	{
    		cout<<current_node->val<<endl;
    		current_node = current_node->next;
    	}
    	current_node->next = NULL;
    	return;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        Solution().reorderList(head);

        string out = listNodeToString(head);
        cout << out << endl;
        break;
    }
    // getline(cin, line);
    // ListNode* head = stringToListNode(line);

    return 0;
}

