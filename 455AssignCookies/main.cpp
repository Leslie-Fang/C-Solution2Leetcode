#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    	sort (g.begin(), g.end()); 
    	sort (s.begin(), s.end());  
        int content = 0;
        vector<int>::iterator it1 = g.begin();
        vector<int>::iterator it2 = s.begin();
        while(it1 != g.end() and it2 != s.end() )
        {
            if(*it2 >= *it1)
            {
                content += 1;
                it1 ++;
                it2 ++;
            }else
            {
                it2 ++;
            }
        } 
        return content;
    }
};

int main()
{
	int a1[4] = {9,10,8,7};
	int b1[2] = {7,8};
	vector<int> a(a1,a1+4);
	vector<int> b(b1,b1+2);
	Solution * mySolution = new Solution();

	cout<<mySolution->findContentChildren(a,b)<<endl;


}