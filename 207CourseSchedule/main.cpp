#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	map<int, vector<int>> mymap;
    	map<int, vector<int>>::iterator it;
    	for(int j=0;j<prerequisites.size();j++)
    	{
    		it = mymap.find(prerequisites[j][0]);
    		if(it == mymap.end())
    		{
    			vector<int> temp;
    			temp.push_back(prerequisites[j][1]);
    			mymap.insert(pair<int,vector<int> >(prerequisites[j][0],temp));
    		}else
    		{
    			it->second.push_back(prerequisites[j][1]);
    		}
    	}
    	vector<int> target;
    	for(int i=0;i<numCourses;i++)
    	{
    		it = mymap.find(i);
    		target.clear();
    		target.push_back(i);
    		if(it != mymap.end())
    		{
    			if(!DFS(numCourses,mymap,target))
    			{
    				return false;
    			}
    		}
    	}
        return true;
    }
    bool DFS(int numCourses, map<int, vector<int>> mymap, vector<int> target, bool unique=false)
    {
    	vector<int> requisites_list;
    	vector<int> subtarget;
    	map<int, vector<int>>::iterator it;
    	for(int i=0;i<target.size();i++)
    	{
    		if(unique && i==target.size()-2)
    		{
    			continue;
    		}
    		it = mymap.find(target[i]);
    		if(it != mymap.end())
    		{
    			for(int j=0;j<it->second.size();j++)
    			{
    				requisites_list.push_back(it->second[j]);
    			}
    		}
    	}
    	vector<int>::iterator it2;
    	for(int i=0;i<requisites_list.size();i++)
    	{
    		it2 = find(target.begin(),target.end(),requisites_list[i]);
    		if(it2 != target.end())
    		{
    			return false;
    		}else
    		{
    			if(mymap.find(requisites_list[i]) == mymap.end())
    			{
    				return true;
    			}
    			subtarget = target;
    			subtarget.push_back(requisites_list[i]);
    			if(!DFS(numCourses,mymap,subtarget,true))
    			{
    				return false;
    			}
    		}
    	}
    	return true;
    }
};
int main(int argc, char ** argv)
{
	vector<vector<int>> prerequisites = {{1,0},{0,1}};
	Solution * mySolution = new Solution();
	cout<<mySolution->canFinish(2,prerequisites)<<endl;
	delete mySolution;
	return 1;
}