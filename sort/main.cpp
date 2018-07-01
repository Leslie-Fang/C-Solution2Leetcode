#include <iostream>
#include "bubble.hpp"
#include "insert.hpp"
#include "heap.hpp"
#include "quick.hpp"
#include "combine.hpp"
using namespace std;
int main(){
	cout<<"hello"<<endl;
	int input[10]={1,5,8,20,16,18,25,2,3,9};
	//bubble_sort(input,sizeof(input)/sizeof(int));
	//insert_sort(input,sizeof(input)/sizeof(int));
	//heap_sort(input,sizeof(input)/sizeof(int));
	//quick_sort(input,0,sizeof(input)/sizeof(int)-1);
	comblne_sort(input,0,sizeof(input)/sizeof(int)-1);
	for(int i=0;i<sizeof(input)/sizeof(int);i++){
		cout<<input[i]<<endl;
	}
	return 0;
}