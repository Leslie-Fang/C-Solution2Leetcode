#include <iostream>
using namespace std;
struct node{
	int val;
	node(int val):val(val){}
	node(){}
	void set(int val){
		this->val=val;
	}
};
int main(int argc, char ** argv){
	node * a = new node(1);
	cout<<a->val<<endl;
	node b;
	b = *a;
	cout<<b.val<<endl;

    cout<<a<<endl;
	cout<<&b<<endl;

	b.set(2);

	cout<<a->val<<endl;
	cout<<b.val<<endl;

	delete a;
	return 0;
}