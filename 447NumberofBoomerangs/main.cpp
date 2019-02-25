#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int getDistance(pair<int, int> a,pair<int, int> b)
	{
		int temp1 = a.first - b.first;
		int temp2 = a.second - b.second;
		return temp1*temp1+temp2*temp2;
	}
    int numberOfBoomerangs(vector<pair<int, int> >& points)
    {
    	int len = points.size();
    	int res = 0;
    	map<int, int> mymap;
    	map<int, int>::iterator it;
    	for(int i=0;i<len;i++)
    	{
    		for(int j=0;j<len;j++)
    		{
    			if(i==j)
    			{
    				continue;
    			}
    			else
    			{
    				int d = getDistance(points[i],points[j]);
    				it = mymap.find(d);
    				if(it == mymap.end())
    				{
    					mymap.insert(std::pair<int, int>(d, 1));
    				}
    				else
    				{
    					it->second += 1;
    				}

    			}
    		}
    		for(it=mymap.begin();it!=mymap.end();it++)
    		{
    			if(it->second >=2)
    			{
    				res += (it->second)*(it->second-1);
    			}
    		}
    		mymap.clear();

    	}
    	return res;
        
    }
};

int main(int argc, char ** argv)
{
	vector<pair<int, int> > input;
	pair<int, int> a(1,0);
	pair<int, int> b(2,0);
	pair<int, int> c(0,0);
	input.push_back(a);
	input.push_back(b);
	input.push_back(c);

	Solution *mySolution = new Solution();
	cout<<mySolution->numberOfBoomerangs(input)<<endl;	

	return 0;
}