#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int len = s.length();
    	vector<vector<int> > dp(len, vector<int>(len,-1));
    	return longestPalindromeSubseq_v2(s,0,len-1,dp);   
    }
    int longestPalindromeSubseq_v2(string & s,int start,int end,vector<vector<int> > & dp)
    {
    	int len = end-start+1;
    	if(len == 0)
    	{
    		return 0;
    	}else if(len == 1)
    	{
    		return 1;
    	}
    	if(s[start] == s[end])
    	{
    		if(dp[start+1][end-1] != -1)
    		{
    			return dp[start+1][end-1]+2;
    		}else
    		{
    			dp[start+1][end-1] = longestPalindromeSubseq_v2(s,start+1,end-1,dp);
    			return dp[start+1][end-1]+2;
    		}
    	}else
    	{
    		int temp1,temp2;
    		if(dp[start][end-1] != -1)
    		{
    			temp1 =  dp[start][end-1];
    		}else
    		{
    			temp1 = longestPalindromeSubseq_v2(s,start,end-1,dp);
    			dp[start][end-1] = temp1;
    		}

    		if(dp[start+1][end] != -1)
    		{
    			temp2 = dp[start+1][end]+2;
    		}else
    		{
    			temp2 = longestPalindromeSubseq_v2(s,start+1,end,dp);
    			dp[start+1][end] = temp2;
    		}
    		return temp1<temp2?temp2:temp1;
    	}  
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->longestPalindromeSubseq(input)<<endl;
	delete mySolution;
	return 0;
}