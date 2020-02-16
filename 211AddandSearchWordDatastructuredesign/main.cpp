#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
public:
	struct node{
		char val;
		bool Final;
		node * next[26];
		//node * next;
		int child_num;
		node(char var):val(val), Final(false), child_num(0){
			for(int i=0;i<26;i++)
			{
				next[i] = NULL;
			}
		}
	};
    /** Initialize your data structure here. */
    WordDictionary() {
        //cout<<"init WordDictionary"<<endl;
        root = new node('.');
        base = int('a');
    }
    
    ~WordDictionary() {
    	//cout<<"delete WordDictionary"<<endl;
    	delete root;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
    	node * temp = root;
    	int index = 0;
    	for(int i=0;i<word.length();i++)
    	{
    		index = int(word[i])-base;
    		if(!temp->next[index])
    		{
    			temp->next[index] = new node(word[i]);
    			temp->child_num += 1;
    		}
    		temp = temp->next[index];
    	}
    	temp->Final = true;
    	return;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool DFSSearch(string word, int index, node * subroot){
    	//bool res = false;
    	if(word[index] == '.')
    	{
			if(subroot->child_num == 0)
			{
				return false;
			}else
			{
				for(int i=0;i<26;i++)
				{
					if(subroot->next[i])
					{
						if(index+1 >= word.length())
						{
							if(subroot->next[i]->Final)
							{
								return true;
							}else{
								continue;
							}
						}
						else if(DFSSearch(word, index+1, subroot->next[i]))
						{
							return true;
						}
					}
				}
			}
    	}else
    	{
			int shift = int(word[index])-base;
			if(!subroot->next[shift])
			{
				return false;
			}else
			{
				if(index+1 >= word.length())
				{
					if(subroot->next[shift]->Final)
					{
						return true;
					}else
					{
						return false;
					}
				}else{
					return DFSSearch(word, index+1, subroot->next[shift]);
				}
			}
    	}
    	return false;
    }
    bool search(string word) {
    	if(word.length() == 0)
    	{
    		return true;
    	}
    	return DFSSearch(word, 0, root);
    }
private:
	node * root;
	int base;
};

int main(int agrc, char ** argv){
	WordDictionary* obj = new WordDictionary();
	obj->addWord("b");
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	cout<<obj->search(".")<<endl;
	cout<<obj->search("..")<<endl;
	cout<<obj->search("bad")<<endl;
	cout<<obj->search("ba")<<endl;
	cout<<obj->search(".ad")<<endl;
	cout<<obj->search("b..")<<endl;;
	delete obj;
	return 0;
}