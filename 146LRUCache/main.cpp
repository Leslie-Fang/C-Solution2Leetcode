#include <iostream>
#include <map>
using namespace std;

class LRUCache {
public:
	struct Node
    {
        int key;
        int val;
        Node * pre;
        Node * post;
        Node(int key, int val) : key(key), val(val), pre(NULL), post(NULL) {}
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->curVolumn = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    
    void move_to_head(Node * node)
    {
    	if(node->pre)
    	{
    		node->pre->post = node->post;
    	}else
    	{
    		return;
    	}
    	if(node->post)
    	{
    		node->post->pre = node->pre;
    	}else
    	{
    		this->tail = node->pre;
    	}
    	node->pre = NULL;
    	node->post = this->head;
    	this->head->pre = node;
    	this->head = node;
    	return;
    }

    void insert_to_head(Node * node)
    {
    	if(this->head == NULL){
    		this->head = node;
    		this->tail = node;
    	}
    	else{
    		node->pre = NULL;
	    	node->post = this->head;
	    	this->head->pre = node;
	    	this->head = node;
    	}
    	return;
    }

    int delete_tail()
    {
    	Node * c = this->tail;
    	int key = this->tail->key;
    	if(this->head == this->tail)
    	{
    		this->head = NULL;
    		this->tail = NULL;
    	}else{
    		this->tail->pre->post = NULL;
    		this->tail = this->tail->pre;
    	}
    	delete c;
    	return key;
    }

    int get(int key) {
    	int res;
    	map<int, Node*>::iterator it = this->myMap.find(key);
    	if(it == this->myMap.end())
    	{
    		res = -1;
    	}else
    	{
    		res = it->second->val;
    		move_to_head(it->second);
    	}
    	return res;
    }
    
    void put(int key, int value) {
    	map<int, Node*>::iterator it = this->myMap.find(key);
    	if(it != this->myMap.end())
    	{
    		it->second->val = value;
    		move_to_head(it->second);
    	}else
    	{
    		Node * newNode = new Node(key, value);
    		this->myMap.insert(pair<int, Node*>(key, newNode));
    		insert_to_head(newNode);
    		if(this->curVolumn < this->capacity)
    		{
    			this->curVolumn += 1;
    		}else
    		{
    			int dkey = delete_tail();
    			this->myMap.erase(dkey);
    		}
    	}
    	return;
    }

private:
	int capacity;
	int curVolumn;
	map<int, Node*> myMap;
	Node* head;
	Node* tail;
};

int main(int argc, char ** argv)
{
	LRUCache * cache = new LRUCache(2);
	cache->put(1, 1);
	cache->put(2, 2);
	cout<<cache->get(1)<<endl;      // returns 1
	cache->put(3, 3);    // evicts key 2
	cout<<cache->get(2)<<endl;       // returns -1 (not found)
	cache->put(4, 4);    // evicts key 1
	cout<<cache->get(1)<<endl;       // returns -1 (not found)
	cout<<cache->get(3)<<endl;       // returns 3
	cout<<cache->get(4)<<endl;       // returns 4
	// cout<<param_1<<endl;
	delete cache;
	return 1;
}