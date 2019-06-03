#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> n_line1;
        for(int i =0;i<10;i++)
        {
            n_line1.push_back(int(line1[i]));
            n_line1.push_back(int(line1[i])-32);
        }
        vector<int> n_line2;
        for(int i =0;i<9;i++)
        {
            n_line2.push_back(int(line2[i]));
            n_line2.push_back(int(line2[i])-32);
        }
        vector<int> n_line3;
        for(int i =0;i<7;i++)
        {
            n_line3.push_back(int(line3[i]));
            n_line3.push_back(int(line3[i])-32);
        }
        vector<string> res;
        int findt = 0;
        for(vector<string>::iterator it = words.begin();it != words.end();it++)
        {
            findt = 0;
            if((*it).length()==0)
            {
                res.push_back("");
                continue;
            }

            vector<int> c;
            if(find(n_line1.begin(), n_line1.end(), int((*it)[0])) != n_line1.end())
            {
                c = n_line1;
            }else if(find(n_line2.begin(), n_line2.end(), int((*it)[0])) != n_line2.end())
            {
                c = n_line2;
            }else
            {
                c = n_line3;
            }
        	for(int i=1;i<(*it).length();i++)
        	{
                if(find(c.begin(), c.end(), int((*it)[i])) == c.end())
                {
                    findt = 1;
                    break;
                }

        	}
            if(findt == 0)
            {
                res.push_back(*it);
            }
            
        }
        return res;
    }
    char line1[10] = {'q','w','e','r','t','y','u','i','o','p'};
    char line2[9] = {'a','s','d','f','g','h','j','k','l'};
    char line3[7] = {'z','x','c','v','b','n','m'};
};

int main(int argc,char**argv)
{
	Solution * mySolution = new Solution();
	vector<string> input;
	input.push_back("Hello");
	input.push_back("Alaska");
	input.push_back("Dad");
	input.push_back("Peace");
	vector<string> words = mySolution->findWords(input);
	        for(vector<string>::iterator it = words.begin();it != words.end();it++)
        {
        	cout<<*it<<endl;
        }
	return 1;

}