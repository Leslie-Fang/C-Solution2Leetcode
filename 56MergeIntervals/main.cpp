#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	//Sort
    	vector<int>* temp = &intervals[0];
    	vector<vector<int>> res;
    	for(int i=0;i<intervals.size()-1;i++)
    	{
    		for(int j=i+1;j<intervals.size();j++)
    		{
    			if(intervals[j-1][0] > intervals[j][0])
    			{
    				temp = &intervals[j-1];
    				intervals[j-1] = intervals[j];
    				intervals[j] = *temp;
    			}
    		}
    	}
    	vector<vector<int>>::iterator it=intervals.begin();
    	int compare = (*it)[1];
    	while(1)
    	{
    		if(compare >= (*next(it))[1])
    		{
    			if(res.back() != *it)
    			{
    				res.push_back(*it);
    			}
    			intervals.erase(next(it));
    		}else if(compare >= (*next(it))[0])
    		{
    			vector<int> temp2;
    			temp2.push_back((*it)[0]);
    			temp2.push_back((*next(it))[1]);
    			res.push_back(temp2);
    			compare = (*next(it))[1];

    			intervals.erase(next(it));
    		}

    		if(next(it) == intervals.end())
    		{
    			break;
    		}
    	}
    	return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();

	delete mySolution;
	return 1;

}