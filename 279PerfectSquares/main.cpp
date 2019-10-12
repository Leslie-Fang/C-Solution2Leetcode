#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	if(n == 0)
    	{
    		return 0;
    	}
    	vector<int> res;
        int min = n;
        DFS(n,res,0,min);
        // for(int i=0;i<res.size();i++)
        // {
        // 	if(min >= res[i])
        // 	{
        // 		min = res[i];
        // 	}
        // }
        return min;
    }

    void DFS(int n, vector<int> & res, int count,int &min){
    	if(n == 1)
    	{
    		res.push_back(count+1);
    		return;
    	}
    	for(int i=int(sqrt(n));i>=1;i--)
    	{
    		int left = n - i * i;
    		if(left == 0)
    		{
    			count += 1;
    			res.push_back(count);
    			if(min > count)
    			{
    				min = count;
    			}
    			return;
    		}else
    		{
    			if(count+1 >= min)
    			{
    				return;
    			}
    			DFS(left,res,count+1,min);
    		}
    	}
    	return;
    }
};

int main(){
	Solution * mySolution = new Solution();
	string input;
	getline(cin, input);
	cout<<mySolution->numSquares(stoi(input))<<endl;
	delete mySolution;
	return 0;
}