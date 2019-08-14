#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
	map<string, unsigned long> looked;
	unsigned long DFS(int d, int f, int target)
	{
		if(d == 0 && target == 0)
		{
			return 1;
		}
		if(d == 0 || target == 0)
		{
			return 0;
		}
		char buff[100];
		snprintf(buff, sizeof(buff), "%d_%d", d, target);
		std::string key = buff;
		map<string, unsigned long>::iterator itr = looked.find(key);
		if(itr != looked.end())
		{
			return itr->second;
		}
		unsigned long res = 0;
		for(int i=1;i<=f;i++)
		{
			if(target >= i)
			{
				res = (res + (unsigned long)DFS(d-1, f, target-i))%1000000007;
			}else
			{
				break;
			}
		}
		itr = looked.find(key);
		if(itr == looked.end())
		{
			looked.insert(pair<string,unsigned long>(key,res));
		}
		//cout<<res%1000000007<<endl;
		return res;
	}
    int numRollsToTarget(int d, int f, int target) {
    	//cout<<1000000008%1000000007<<endl;
        return DFS(d,f,target);
    }
};

int main()
{	
	Solution * mySolution = new Solution();
	cout<< mySolution->numRollsToTarget(30,30,500)<<endl;
	//cout<< mySolution->numRollsToTarget(1,6,3)<<endl;
	delete mySolution;
	return 0;
}