#include <iostream>

using namespace std;
class Trie {
public:
	struct Node
	{
		char val;
		bool final;
		Node * leaves[26];
		Node(char value):val(value){
			val = value;
			for(int i=0;i<26;i++)
			{
				leaves[i] = NULL;
			}
			final = false;
		}
		~Node()
		{
			for(int i=0;i<26;i++)
			{
				delete leaves[i];
			}
		}
		void insert(int pos, char value)
		{
			leaves[pos] = new Node(value);
		}

	};
	int depth;
	Node * root;
    /** Initialize your data structure here. */
    Trie() {
		depth = 0;
		root = new Node('0');
    }
    ~Trie() {
    	delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	Node * current = root;
    	for(int i=0;i<word.size();i++)
    	{
    		if(current->leaves[int(word[i])-int('a')] == NULL)
    		{
    			current->leaves[int(word[i])-int('a')] = new Node(word[i]);
    		}
    		current = current->leaves[int(word[i])-int('a')];
    	}
    	//cout<<current->val<<endl;
    	current->final = true;
    	return;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * current = root;
    	for(int i=0;i<word.size();i++)
    	{
    		//cout<<current->val<<endl;
    		if(current->leaves[int(word[i])-int('a')] == NULL)
    		{
    			return false;
    		}
    		current = current->leaves[int(word[i])-int('a')];
    	}
    	return current->final;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * current = root;
    	for(int i=0;i<prefix.size();i++)
    	{
    		if(current->leaves[int(prefix[i])-int('a')] == NULL)
    		{
    			return false;
    		}
    		current = current->leaves[int(prefix[i])-int('a')];
    	}
    	return true;
    }
};

int main(int argc, char ** argv)
{
	Trie trie = Trie();

	trie.insert("abc");
	cout<<trie.search("abd")<<endl;   // returns true
	// cout<<trie.search("apple")<<endl;   // returns true
	// cout<<trie.search("app")<<endl;     // returns false
	// cout<<trie.startsWith("app")<<endl; // returns true
	// trie.insert("app");   
	// cout<<trie.search("app")<<endl;     // returns true
	return 1;
}