#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
    	vector<int> compare_h(heights.begin(),heights.begin()+heights.size());
    	sort(compare_h.begin(),compare_h.begin()+compare_h.size());
    	int res = 0;
    	for(int i=0;i<compare_h.size();i++)
    	{
    		if(compare_h[i] != heights[i])
    		{
    			res += 1;
    		}
    	}

        return res;
    }
};

int main(int argc,char ** argv)
{
	Solution * mySolution = new Solution();
	int inputt[6] = {1,1,4,2,1,3};
	vector<int> input(inputt,inputt+6);
	cout<<mySolution->heightChecker(input)<<endl;
	return 0;
}