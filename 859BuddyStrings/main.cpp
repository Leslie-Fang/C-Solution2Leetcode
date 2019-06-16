#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
    	map<char,int> mapA;
    	int lengthA = A.length();
    	int lengthB = B.length();
    	if(lengthA != lengthB)
    	{
    		return false;
    	}
    	if(A == B)
    	{
    		for(int i=0;i<lengthA;i++)
	    	{
	    		if(mapA.find(A[i]) == mapA.end())
	    		{
	    			mapA.insert(pair<char,int>(A[i],1));
	    		}else{
	    			return true;
	    		}
	    	}
	    	return false;
    	}
    	int count = 0;
    	int diff[2] = {0,0};
    	for(int i=0;i<lengthA;i++)
    	{
    		if(A[i] != B[i])
    		{
    			if(count > 1)
    			{
    				return false;
    			}
    			diff[count] = i;
    			count += 1;
    		}
    	}
    	if(count == 1)
    	{
    		return false;
    	}
    	char temp = A[diff[0]];
    	A[diff[0]] = A[diff[1]];
    	A[diff[1]] = temp;
    	if(A != B)
    	{
    		return false;
    	}
        return true;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	cout<<mySolution->buddyStrings("aa","aa")<<endl;
	return 0;
}