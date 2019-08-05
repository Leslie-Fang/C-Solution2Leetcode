#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len_a = text1.size();
        int len_b = text2.size();
        int temp[len_a+1][len_b+1] = {0};
        for(int i=1;i<=len_a;i++)
        {
        	for(int j=1;j<=len_b;j++)
        	{
        		if(text1[i-1] == text2[j-1])
        		{
					temp[i][j] = temp[i-1][j-1] + 1;
        		}else
        		{
        			temp[i][j] = max(temp[i-1][j],temp[i][j-1]);
        		}
        	}
        }
        return temp[len_a][len_b];
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	cout<<mySolution->longestCommonSubsequence("abc","def" )<<endl;
	return 0;
}