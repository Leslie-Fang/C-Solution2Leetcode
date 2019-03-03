#include <iostream>
#include <vector>
#include<utility>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	int len = people.size();
    	if(len == 0)
    	{
    		return people;
    	}
    	vector<int> pos;
    	vector<int> deletePos;
    	for(int i=0;i<len;i++)
    	{
    		pos.push_back(i);
    	}
        pair<int, int> resultList[len];
        vector<pair<int, int> > temp;
        while(people.size() != 0)
        {
        	deletePos.clear();
			temp = findMinPairs(people);
			for(int i=0;i<temp.size();i++)
			{
				int insertPos = pos[temp[i].second];
				resultList[insertPos] =  temp[i];
				deletePos.push_back(insertPos);
			}
			for(int i=0;i<deletePos.size();i++)
			{
				for(int j=0;j<pos.size();j++)
				{
					if(pos[j] == deletePos[i])
					{
						pos.erase(pos.begin()+j);
					}
				}
			}
        }
        vector<pair<int, int> > result(resultList,resultList+len);
    	return result;
    }
    vector<pair<int, int> > findMinPairs(vector<pair<int, int> >& people)
    {
    	vector<pair<int, int> > result;
    	int minVal = people[0].first;
    	for(vector<pair<int, int> >::iterator it = people.begin();it != people.end();it++)
    	{
    		if((*it).first < minVal)
    		{
    			minVal = (*it).first;
    			result.clear();
    			result.push_back(*it);
    		}else if((*it).first == minVal)
    		{
    			result.push_back(*it);
    		}
    	}
    	for(int i=0;i<people.size();i++)
    	{
    		if(people[i].first == minVal)
    		{
    			people.erase(people.begin()+i);
    			i = i -1;
    		}
    	}
    	 for(int i=0;i<people.size();i++)
    	{
    		cout<<people[i].first<<endl;
    	}
    	for(int i=0;i<result.size();i++)
    	{
    		cout<<result[i].first<<endl;
    	}
    	return result;
    }
};

int main(int argc, char ** argv)
{
	vector<pair<int, int> > people;
	people.push_back(make_pair(9,0));
	people.push_back(make_pair(7,0));
	people.push_back(make_pair(1,9));
	people.push_back(make_pair(3,0));
	people.push_back(make_pair(2,7));
	people.push_back(make_pair(5,3));
	people.push_back(make_pair(6,0));
	people.push_back(make_pair(3,4));
	people.push_back(make_pair(6,2));
	people.push_back(make_pair(5,2));
	Solution * mySolution = new Solution();
	mySolution->reconstructQueue(people);
	return 0;
}