#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int comp1 = 0;
    	int comp2 = 0;
    	string temp1 = "";
    	string temp2 = "";
    	int index1 = 0;
    	int index2 = 0;
    	if(version1.size() == 0 && version2.size() == 0)
    	{
    		return 0;
    	}else if(version1.size() == 0)
    	{
    		return -1;
    	}else if(version2.size() == 0)
    	{
    		return 1;
    	}
    	while(1)
    	{
    		temp1 = "";
    		temp2 = "";
    		while(index1 < version1.size())
    		{
    			if(version1[index1] != '.')
    			{
					temp1 += version1[index1];
    			}else
    			{
					istringstream iss (temp1);
					iss >> comp1;
					iss.clear();
					break;
    			}
    			index1 += 1;
    		}
    		if(index1 == version1.size())
    		{
    			istringstream iss (temp1);
				iss >> comp1;
				iss.clear();
    		}
    		while(index2 < version2.size())
    		{
    			if(version2[index2] != '.')
    			{
					temp2 += version2[index2];
    			}else
    			{
					istringstream iss (temp2);
					iss >> comp2;
					iss.clear();
					break;
    			}
    			index2 += 1;
    		}
    		if(index2 == version2.size())
    		{
    			istringstream iss (temp2);
				iss >> comp2;
				iss.clear();
    		}
    		cout<<comp1<<endl;
    		cout<<comp2<<endl;

    		// cout<<index1<<endl;
    		// cout<<index2<<endl;
    		if(comp1 > comp2)
    		{
    			return 1;
    		}else if(comp1 < comp2)
    		{
    			return -1;
    		}else
    		{
    			if(index1 == version1.size() && index2 == version2.size())
    			{
    				return 0;
    			}else if(index1 == version1.size())
    			{
    				index2 += 1;
    				temp2 = "";
    				while(index2 < version2.size())
		    		{
		    			if(version2[index2] != '.')
		    			{
							temp2 += version2[index2];
		    			}else
		    			{
							istringstream iss (temp2);
							iss >> comp2;
							iss.clear();
							if(comp2 != 0)
							{
								return -1;
							}
							temp2 = "";
		    			}
		    			index2 += 1;
		    		}
		    		if(index2 == version2.size())
		    		{
		    			istringstream iss (temp2);
						iss >> comp2;
						iss.clear();
						if(comp2 != 0)
						{
							return -1;
						}
						else
						{
							return 0;
						}
		    		}
    				return -1;
    			}else if(index2 == version2.size())
    			{	
    				cout<<"in index2 only == 0"<<endl;
    				temp1 = "";
    				index1 += 1;
    				while(index1 < version1.size())
		    		{
		    			if(version1[index1] != '.')
		    			{
							temp1 += version1[index1];
		    			}else
		    			{
							istringstream iss (temp1);
							iss >> comp1;
							iss.clear();
							if(comp1 != 0)
							{
								return 1;
							}
							temp1 = "";
		    			}
		    			index1 += 1;
		    		}
		    		cout<<"last temp1 "<<temp1<<endl;
		    		if(index1 == version1.size())
		    		{
		    			istringstream iss (temp1);
						iss >> comp1;
						iss.clear();
						if(comp1 != 0)
						{
							return 1;
						}
						else
						{
							return 0;
						}
		    		}
    				return 1;
    			}else
    			{
    				index1 += 1;
    				index2 += 1;
    			}
    		}

    	}

    	return 1;
        
    }
};
int main()
{
	string input1;
	string input2;
	getline(cin,input1);
	getline(cin,input2);
	Solution * mySolution = new Solution();
	cout<<mySolution->compareVersion(input1,input2)<<endl;
	delete mySolution;
	return 1;
}