#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int DFS(int label, vector<int> & res, int level, int before_sum)
    {
        if(label <= 0)
        {
            return -1;
        }else
        {
            if(label > pow(2,level))
            {
                before_sum += pow(2,level);
                int temp = DFS(label-pow(2,level), res, level+1, before_sum);
                if(level%2 == 0)
                {
                    res.insert(res.begin(),before_sum-pow(2,level)+temp/2+1);
                }else
                {
                    res.insert(res.begin(),before_sum-temp/2);
                }
                return temp/2;
            }else 
            {
                res.insert(res.begin(),label + before_sum);
                if(level%2 == 0)
                {
                    return label-1;
                }else
                {
                    return pow(2,level) - label;
                }
            }
        }
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        DFS(label, res, 0, 0);
        return res;
    }
};

int main(int argc, char ** argv)
{
    Solution * mySolution;
    vector<int> res = mySolution->pathInZigZagTree(26);
    for(vector<int>::iterator it = res.begin() ; it != res.end(); it++)
    {
        cout << *it <<endl;
    }
	return 1;
}