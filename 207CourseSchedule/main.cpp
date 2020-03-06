#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
	struct Node
	{
		int val;
		vector<Node*> next;
		Node(int value):val(value){}
		~Node(){next.clear();}
	};
	bool DFS(bool* goThrough, Node * cur, bool* memory, int & numCourses)
	{
		// if(find(goThrough.begin(), goThrough.end(), cur)!=goThrough.end())
		// {
		// 	return false;
		// }
		bool goThrough2[numCourses] = {false};
		memcpy(goThrough2, goThrough, sizeof(bool) * numCourses);
		// if(goThrough2.find(cur->val) != goThrough2.end())
		// {
		// 	return false;
		// }
		//bool res = true;
		//goThrough.push_back(cur);
		//map<int, bool>::iterator it3;
		//goThrough2.insert(pair<int,bool>(cur->val, true));
		if(goThrough2[cur->val])
		{
			return false;
		}
		goThrough2[cur->val] = true;
		for(vector<Node*>::iterator it = cur->next.begin(); it != cur->next.end();it++)
		{
			//res = res || DFS(root, *it);
			//it3 = memory.find((*it)->val);
			if(memory[(*it)->val])
			{
				continue;
			}
			if(!DFS(goThrough2, *it, memory, numCourses))
			{
				return false;
			}
			memory[(*it)->val] = true;
			//memory.insert(pair<int, bool>((*it)->val, true));
		}
		return true;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	bool res = true;
    	Node * first;
    	Node * second;
    	map<int, Node*>::iterator it;
    	for(int i=0;i<prerequisites.size();i++)
    	{
    		it = myMap.find(prerequisites[i][0]);
    		if(it == myMap.end())
    		{
    			first = new Node(prerequisites[i][0]);
    			myMap.insert(pair<int,Node*>(prerequisites[i][0],first));
    		}else
    		{
    			first = it->second;
    		}
    		it = myMap.find(prerequisites[i][1]);
    		if(it == myMap.end())
    		{
    			second = new Node(prerequisites[i][1]);
    			myMap.insert(pair<int,Node*>(prerequisites[i][1],second));
    		}else
    		{
    			second = it->second;
    		}
    		second->next.push_back(first);
    	}
    	//vector<Node *> goThrough;
    	//map<int, bool> memory;
    	//map<int, bool>::iterator it3;

    	bool memory[numCourses] = {false};
    	for(it = myMap.begin();it!=myMap.end();it++)
    	{
    		//map<int, bool> goThrough;
    		//goThrough.clear();
    		//goThrough.push_back(it->second);
    		bool goThrough[numCourses] = {false};
    		goThrough[it->first] = true;
    		//goThrough.insert(pair<int,bool>(it->first, true));
    		//if(memory.find)
    		//it3 = memory.find(it->first);
    		if(memory[it->first])
    		{
    			continue;
    		}
    		for(vector<Node*>::iterator it2 = it->second->next.begin();it2 != it->second->next.end();it2++)
    		{
    			//it3 = memory.find((*it2)->val);
	    		if(memory[(*it2)->val])
	    		{
	    			continue;
	    		}
    			if(!DFS(goThrough,*it2, memory, numCourses))
    			{
    				return false;
    			}
    			memory[(*it2)->val] = true;
    			//memory.insert(pair<int, bool>((*it2)->val, true));
    		}
    		memory[it->first] = true;
    		//memory.insert(pair<int, bool>(it->first,true));
    	}
    	return true; 
    }
    ~Solution()
    {
    	map<int, Node*>::iterator it;
    	for(it = myMap.begin();it!=myMap.end();it++)
    	{
    		delete it->second;
    	}
    }
private:
	map<int, Node*> myMap;
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	vector<vector<int>> prerequisites = {{2,0},{1,0},{3,1},{3,2},{1,3}};
	cout<<mySolution->canFinish(4,prerequisites)<<endl;
	delete mySolution;
	return 1;
}