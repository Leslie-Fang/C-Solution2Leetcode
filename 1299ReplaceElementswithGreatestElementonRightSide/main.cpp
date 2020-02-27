#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    	list<int> res;
    	int max = arr[arr.size()-1];
    	for(int i=arr.size()-1;i>=0;i--)
    	{
    		res.push_front(max);
    		if(max < arr[i])
    		{
    			max = arr[i];
    		}
    	}
    	vector<int> res2(res.begin(), res.end());
    	res2[res2.end()-1] = -1;
    	return res2;
    }
};

int main(int argc, char ** argv)
{

	return 0;
}