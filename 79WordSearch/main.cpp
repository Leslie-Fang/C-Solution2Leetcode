#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool recrusive_look(vector<char> & serial,vector<bool> & looked,vector<int> & index,string & word, int cur_index, int unit_length, int word_index)
	{
		if(word_index >= word.size())
		{
			return true;
		}
		if(cur_index-1 >= 0 && cur_index%unit_length != 0)
		{
        	if(serial[cur_index-1] == word[word_index] && !looked[cur_index-1])
        	{
        		looked[cur_index-1] = true;
        		index.push_back(cur_index-1);
        		if(recrusive_look(serial,looked,index,word,cur_index-1,unit_length,word_index+1))
        		{
        			return true;
        		}
        		looked[cur_index-1] = false;
        		index.pop_back();
        	}
        }
         if(cur_index+1 < serial.size() && (cur_index+1)%unit_length != 0)
         {
        	if(serial[cur_index+1] == word[word_index] && !looked[cur_index+1])
        	{
        		looked[cur_index+1] = true;
        		index.push_back(cur_index+1);
        		if(recrusive_look(serial,looked,index,word,cur_index+1,unit_length,word_index+1))
        		{
        			return true;
        		}
        		looked[cur_index+1] = false;
        		index.pop_back();
        	}
        }
        if(cur_index-unit_length >= 0)
        {
        	if(serial[cur_index-unit_length] == word[word_index] && !looked[cur_index-unit_length])
        	{
        		looked[cur_index-unit_length] = true;
        		index.push_back(cur_index-unit_length);
        		if(recrusive_look(serial,looked,index,word,cur_index-unit_length,unit_length,word_index+1))
        		{
        			return true;
        		}
        		looked[cur_index-unit_length] = false;
        		index.pop_back();
        	}
        }
        if(cur_index+unit_length < serial.size())
        {
        	if(serial[cur_index+unit_length] == word[word_index] && !looked[cur_index+unit_length])
        	{
        		looked[cur_index+unit_length] = true;
        		index.push_back(cur_index+unit_length);
        		if(recrusive_look(serial,looked,index,word,cur_index+unit_length,unit_length,word_index+1))
        		{
        			return true;
        		}
        		looked[cur_index+unit_length] = false;
        		index.pop_back();
        	}
        }
        //}
		return false;
	}
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.size() == 0 || board[0].size() == 0)
    	{
    		return false;
    	}
    	vector<char> serial;
    	vector<bool> looked;
    	vector<int> index;
    	int unit_length = board[0].size();
        for(vector<vector<char>>::iterator it1 = board.begin();it1 != board.end();it1++)
        {
        	for(vector<char>::iterator it2=it1->begin();it2 != it1->end();it2++)
        	{
        		serial.push_back(*it2);
        		looked.push_back(false);
        	}
        }
        for(int i=0;i<serial.size();i++)
        {
        	if(serial[i] == word[0])
        	{
        		cout<<serial[i]<<endl;
        		looked[i] = true;
        		index.push_back(i);
        		if(recrusive_look(serial,looked,index,word,i,unit_length,1))
        		{
        			return true;
        		}
        		looked[i] = false;
        		index.clear();
        	}
        	// clear the temp index
        	// for(int j=0;j<index.size();j++)
        	// {
        	// 	looked[index[j]] = false;
        	// }
        	// index.clear();
        }
        return false;
    }
};

int main(int argc, char ** argv){
	return 0;
}