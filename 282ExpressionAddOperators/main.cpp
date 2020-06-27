#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void subAddOperators(string & num, int & target, vector<string> & res, vector<int> cNum, vector<char> cBinary, int index, vector<int> cNumRecord, vector<char> cBinaryRecord)
	{
		if(index >= num.size())
		{
			if(cNum.size() == 1 && cBinary.size() == 0)
			{
				if(cNum[0] == target)
				{

				}
			}
			return;
		}
		if(cNum.size() == 1 && cBinary.size() == 0)
		{
			cBinary.push_back('+');
			cBinaryRecord.push_back('+');
			subAddOperators(num, target, res, cNum, cBinary, index, cNumRecord, cBinaryRecord);
			cBinary.pop_back();
			cBinaryRecord.pop_back();
			
			cBinary.push_back('-');
			cBinaryRecord.push_back('-');
			subAddOperators(num, target, res, cNum, cBinary, index, cNumRecord, cBinaryRecord);
			cBinary.pop_back();
			cBinaryRecord.pop_back();
			
			cBinary.push_back('*');
			cBinaryRecord.push_back('*');
			subAddOperators(num, target, res, cNum, cBinary, index, cNumRecord, cBinaryRecord);
			cBinary.pop_back();
			cBinaryRecord.pop_back();

		}else if(cNum.size() == 1 && cBinary.size() == 1)
		{
			string tempStringNum = "";
			for(int i=index;i<num.size();i++)
			{
				tempStringNum += num[i];
				cNumRecord.push_back(atoi(tempStringNum.c_str()));
				if(cBinary[0] == '+' || cBinary[0] == '-')
				{
					cNum.push_back(atoi(tempStringNum.c_str()));
					subAddOperators(num, target, res, cNum, cBinary, i+1, cNumRecord, cBinaryRecord);
					cNum.pop_back();
					
				}else
				{
					//cBinary[0] == '*'
					vector<int> subCNum;
        			vector<char> subCBinary;
					//tempStringNum += num[i];
					int sumres = atoi(tempStringNum.c_str()) * cNum[0];
					subCNum.push_back(sumres);
					//cBinaryRecord.push_back('*');
					subAddOperators(num, target, res, subCNum, subCBinary, i+1, cNumRecord, cBinaryRecord);
				}
				cNumRecord.pop_back();
			}
		}else if(cNum.size() == 2 && cBinary.size() == 1)
		{
			int sumres = 0;
			vector<int> subCNum;
        	vector<char> subCBinary;
			//process +
			if(cBinary[0] == '+')
			{
				sumres = cNum[0] + cNum[1];
			}else
			{
				//cBinary[0] == '-'
				sumres = cNum[0] - cNum[1];	
			}
			subCNum.push_back(sumres);
			subCBinary.push_back('+');
			subAddOperators(num, target, res, subCNum, subCBinary, index);
			
			sumres = 0;
			subCNum.clear();
			subCBinary.clear();
			//process -
			if(cBinary[0] == '+')
			{
				sumres = cNum[0] + cNum[1];
			}else
			{
				//cBinary[0] == '-'
				sumres = cNum[0] - cNum[1];	
			}
			subCNum.push_back(sumres);
			subCBinary.push_back('-');
			subAddOperators(num, target, res, subCNum, subCBinary, index);

			//process *
			cBinary.push_back('*');
			subAddOperators(num, target, res, cNum, cBinary, index);
		}else if(cNum.size() == 2 && cBinary.size() == 2)
		{
			string tempStringNum = "";
			int base = cNum[1];
			cBinary.pop_back();
			cNum.pop_back();
			for(int i =index;i<num.size();i++)
	        {
	        	tempStringNum += num[i];
	        	cNum.push_back(atoi(tempStringNum.c_str())*base);
	        	//cout<<atoi(tempStringNum.c_str())<<endl;
	        	subAddOperators(num, target, res, cNum, cBinary, i+1);
	        	cNum.pop_back();
	        }
		}
		return;
	}
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        vector<int> cNum;
        vector<char> cBinary;
        vector<int> cNumRecord;
        vector<char> cBinaryRecord;
        string tempStringNum = "";
        for(int i =0;i<num.size();i++)
        {
        	tempStringNum += num[i];
        	cNum.clear();
        	cNum.push_back(atoi(tempStringNum.c_str()));
        	//cout<<atoi(tempStringNum.c_str())<<endl;
        	subAddOperators(num, target, res, cNum, cBinary, i+1, cNumRecord, cBinaryRecord);
        }
        return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	vector<string> res = mySolution->addOperators("123", 6);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;
	return 0;
}